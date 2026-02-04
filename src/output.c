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
