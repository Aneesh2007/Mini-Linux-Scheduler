#include <stdio.h>
#include "scheduler.h"

void round_robin(Process p[], int n, int quantum,
                 GanttEntry gantt[], int *gantt_len) {

    int time = 0, completed = 0;
    int queue[MAX_PROCESSES];
    int front = 0, rear = 0;

    int visited[MAX_PROCESSES] = {0};
    *gantt_len = 0;

    while (completed < n) {

        /* Add newly arrived processes */
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time &&
                !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        /* CPU idle */
        if (front == rear) {
            time++;
            continue;
        }

        int idx = queue[front++];

        int exec_time =
            (p[idx].remaining_time < quantum)
            ? p[idx].remaining_time
            : quantum;

        for (int t = 0; t < exec_time; t++) {
            gantt[*gantt_len].time = time;
            gantt[*gantt_len].pid = p[idx].pid;
            (*gantt_len)++;

            time++;
            p[idx].remaining_time--;

            /* Add processes that arrive during execution */
            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= time &&
                    !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }

            if (p[idx].remaining_time == 0)
                break;
        }

        if (p[idx].remaining_time == 0) {
            p[idx].completion_time = time;
            p[idx].turnaround_time =
                time - p[idx].arrival_time;
            p[idx].waiting_time =
                p[idx].turnaround_time - p[idx].burst_time;
            completed++;
        } else {
            queue[rear++] = idx;  // rotate
        }
    }
}
