#include <stdio.h>
#include "scheduler.h"

void fcfs(Process[], int, GanttEntry[], int*);

int main() {
    Process p[] = {
        {1, 0, 5, 5},
        {2, 1, 3, 3},
        {3, 2, 1, 1}
    };
    int n = 3;

    GanttEntry gantt[MAX_GANTT];
    int gantt_len;

    fcfs(p, n, gantt, &gantt_len);

    printf("Gantt Chart:\n");
    for (int i = 0; i < gantt_len; i++)
        printf("| P%d ", gantt[i].pid);
    printf("|\n");

    printf("\nPID\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);

    return 0;
}
