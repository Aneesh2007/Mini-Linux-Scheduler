#include <stdio.h>
#include "scheduler.h"

void read_processes(Process p[], int *n) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        p[i].pid = i + 1;

        printf("Enter Arrival Time and Burst Time for P%d: ",
               p[i].pid);
        scanf("%d %d",
              &p[i].arrival_time,
              &p[i].burst_time);

        p[i].remaining_time = p[i].burst_time;
        p[i].completion_time = 0;
        p[i].turnaround_time = 0;
        p[i].waiting_time = 0;
    }
}
