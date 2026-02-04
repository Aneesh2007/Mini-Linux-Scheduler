#include <stdio.h>
#include "scheduler.h"

void sjf(Process p[], int n, GanttEntry gantt[], int *gantt_len) {
    int time = 0;
    int completed = 0;
    *gantt_len = 0;

    while (completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time &&
                p[i].remaining_time > 0 &&
                p[i].burst_time < min_bt) {

                min_bt = p[i].burst_time;
                idx = i;
            }
        }

        // If no process is available, CPU is idle
        if (idx == -1) {
            time++;
            continue;
        }
        for (int t = 0; t < p[idx].burst_time; t++) {
            gantt[*gantt_len].time = time;
            gantt[*gantt_len].pid = p[idx].pid;
            (*gantt_len)++;
            time++;
        }

        p[idx].remaining_time = 0;
        p[idx].completion_time = time;
        p[idx].turnaround_time =
            time - p[idx].arrival_time;
        p[idx].waiting_time =
            p[idx].turnaround_time - p[idx].burst_time;

        completed++;
    }
}
