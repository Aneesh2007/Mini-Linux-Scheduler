#include <stdio.h>
#include "scheduler.h"

void read_processes(Process p[], int *n) {
    do {
        printf("Enter number of processes (1-%d): ", MAX_PROCESSES);
        scanf("%d", n);
        if (*n < 1 || *n > MAX_PROCESSES)
            printf("Invalid: must be between 1 and %d.\n", MAX_PROCESSES);
    } while (*n < 1 || *n > MAX_PROCESSES);

    for (int i = 0; i < *n; i++) {
        p[i].pid = i + 1;

        do {
            printf("Enter Arrival Time for P%d (>= 0): ", p[i].pid);
            scanf("%d", &p[i].arrival_time);
            if (p[i].arrival_time < 0)
                printf("Invalid: arrival time must be >= 0.\n");
        } while (p[i].arrival_time < 0);

        do {
            printf("Enter Burst Time for P%d (> 0): ", p[i].pid);
            scanf("%d", &p[i].burst_time);
            if (p[i].burst_time <= 0)
                printf("Invalid: burst time must be > 0.\n");
        } while (p[i].burst_time <= 0);

        p[i].remaining_time = p[i].burst_time;
        p[i].completion_time = 0;
        p[i].turnaround_time = 0;
        p[i].waiting_time = 0;
    }
}
