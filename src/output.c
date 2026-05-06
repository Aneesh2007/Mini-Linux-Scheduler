#include <stdio.h>
#include "scheduler.h"

void print_gantt(GanttEntry gantt[], int len) {
    if (len == 0) {
        printf("\nGantt Chart: (empty)\n");
        return;
    }

    /* Compress consecutive same-PID entries into segments */
    int seg_pid[MAX_GANTT];
    int seg_start[MAX_GANTT];
    int seg_end[MAX_GANTT];
    int nseg = 0;

    seg_pid[0]   = gantt[0].pid;
    seg_start[0] = gantt[0].time;
    seg_end[0]   = gantt[0].time + 1;
    nseg = 1;

    for (int i = 1; i < len; i++) {
        if (gantt[i].pid == seg_pid[nseg - 1]) {
            seg_end[nseg - 1] = gantt[i].time + 1;
        } else {
            seg_pid[nseg]   = gantt[i].pid;
            seg_start[nseg] = gantt[i].time;
            seg_end[nseg]   = gantt[i].time + 1;
            nseg++;
        }
    }

    /* Print process blocks: each cell is " P%-3d|" = 7 chars wide */
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < nseg; i++)
        printf(" P%-3d|", seg_pid[i]);

    /* Print actual time labels aligned with cell boundaries (%-7d) */
    printf("\n%-7d", seg_start[0]);
    for (int i = 0; i < nseg; i++)
        printf("%-7d", seg_end[i]);
    printf("\n");
}

void print_process_table(Process p[], int n) {
    float total_tat = 0, total_wt = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);

        total_tat += p[i].turnaround_time;
        total_wt += p[i].waiting_time;
    }

    printf("\nAverage Turnaround Time (ATAT): %.2f\n",
           total_tat / n);
    printf("Average Waiting Time (AWT): %.2f\n",
           total_wt / n);
}
