#include <stdio.h>
#include "scheduler.h"

/* Reset process state before running a scheduler */
void reset_processes(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].remaining_time = p[i].burst_time;
        p[i].completion_time = 0;
        p[i].turnaround_time = 0;
        p[i].waiting_time = 0;
    }
}

int main() {
    Process p[MAX_PROCESSES];
    GanttEntry gantt[MAX_GANTT];

    int n;
    int choice;
    int quantum;
    int gantt_len;

    /* Read input from user */
    read_processes(p, &n);

    /* Menu */
    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. FCFS\n");
    printf("2. SJF (Non-Preemptive)\n");
    printf("3. SRTF (Preemptive)\n");
    printf("4. Round Robin\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    /* Reset state before running algorithm */
    reset_processes(p, n);

    switch (choice) {
        case 1:
            fcfs(p, n, gantt, &gantt_len);
            break;

        case 2:
            sjf(p, n, gantt, &gantt_len);
            break;

        case 3:
            srtf(p, n, gantt, &gantt_len);
            break;

        case 4:
            printf("Enter Time Quantum: ");
            scanf("%d", &quantum);
            round_robin(p, n, quantum, gantt, &gantt_len);
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    /* Output */
    print_gantt(gantt, gantt_len);
    print_process_table(p, n);

    return 0;
}
