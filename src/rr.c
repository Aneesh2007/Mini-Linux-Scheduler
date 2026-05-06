#include <stdio.h>
#include "scheduler.h"

void round_robin(Process p[], int n, int quantum,
                 GanttEntry gantt[], int *gantt_len) {

    int time = 0, completed = 0;
    /*
     * Use a circular queue large enough for all enqueue operations.
     * In the worst case every time-unit produces a re-queue, so
     * MAX_GANTT + MAX_PROCESSES slots are sufficient.
     */
    int queue[MAX_GANTT + MAX_PROCESSES];
    int front = 0, rear = 0;
    int queue_cap = MAX_GANTT + MAX_PROCESSES;

    int visited[MAX_PROCESSES] = {0};
    *gantt_len = 0;

    while (completed < n) {

        /* Add newly arrived processes to the ready queue */
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && !visited[i]) {
                queue[rear % queue_cap] = i;
                rear++;
                visited[i] = 1;
            }
        }

        /* CPU idle — advance time */
        if (front == rear) {
            time++;
            continue;
        }

        int idx = queue[front % queue_cap];
        front++;

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
                if (p[i].arrival_time <= time && !visited[i]) {
                    queue[rear % queue_cap] = i;
                    rear++;
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
            queue[rear % queue_cap] = idx;  /* rotate back */
            rear++;
        }
    }
}
