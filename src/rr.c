#include <stdio.h>
#include "scheduler.h"

void round_robin(Process p[], int n, int quantum,
                 GanttEntry gantt[], int *gantt_len) {

    int time = 0, completed = 0;
    int queue[MAX_PROCESSES];
    int front = 0, rear = 0;
    int in_queue[MAX_PROCESSES] = {0};

    *gantt_len = 0;

    while (completed < n) {

        
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time &&
                p[i].remaining_time > 0 &&
                !in_queue[i]) {

                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        
        if (front == rear) {
            time++;
            continue;
        }

        int idx = queue[front++];
        in_queue[idx] = 0;

        int exec_time =
            (p[idx].remaining_time < quantum)
            ? p[idx].remaining_time
            : quantum;

        
        for (int t = 0; t < exec_time; t++) {
            gantt[*gantt_len].time = time;
            gantt[*gantt_len].pid = p[idx].pid;
            (*gantt_len)++;
            time++;

            
            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= time &&
                    p[i].remaining_time > 0 &&
                    !in_queue[i]) {

                    queue[rear++] = i;
                    in_queue[i] = 1;
                }
            }
        }

        p[idx].remaining_time -= exec_time;

        
        if (p[idx].remaining_time == 0) {
            p[idx].completion_time = time;
            p[idx].turnaround_time =
                time - p[idx].arrival_time;
            p[idx].waiting_time =
                p[idx].turnaround_time - p[idx].burst_time;
            completed++;
        } else {
            
            queue[rear++] = idx;
            in_queue[idx] = 1;
        }
    }
}
