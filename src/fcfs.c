#include <stdio.h>
#include "scheduler.h"

void fcfs(Process p[], int n, GanttEntry gantt[], int *gantt_len) {
    int time = 0;
    *gantt_len = 0;

    /* Sort by arrival time (selection sort) */
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j].arrival_time < p[min_idx].arrival_time)
                min_idx = j;
        }
        if (min_idx != i) {
            Process tmp = p[i];
            p[i] = p[min_idx];
            p[min_idx] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time)
            time = p[i].arrival_time;

        /* Execute full process */
        for (int t = 0; t < p[i].burst_time; t++) {
            gantt[*gantt_len].time = time;
            gantt[*gantt_len].pid = p[i].pid;
            (*gantt_len)++;
            time++;
        }

        p[i].completion_time = time;
        p[i].turnaround_time = time - p[i].arrival_time;
        p[i].waiting_time =
            p[i].turnaround_time - p[i].burst_time;
    }
}
