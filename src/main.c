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

    int quantum = 2;
    round_robin(p, n, quantum, gantt, &gantt_len);

    print_gantt(gantt, gantt_len);
    print_process_table(p, n);
    

    return 0;
}
