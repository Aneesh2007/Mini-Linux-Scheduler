#include <stdio.h>
#include "scheduler.h"

void print_gantt(GanttEntry gantt[], int len) {
    printf("\nGantt Chart:\n|");

    for (int i = 0; i < len; i++) {
        printf(" P%d |", gantt[i].pid);
    }

    printf("\n0");
    for (int i = 1; i <= len; i++) {
        printf("   %d", i);
    }
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
