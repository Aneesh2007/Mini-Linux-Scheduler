#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_PROCESSES 20
#define MAX_GANTT 1000

/* Process Control Block */
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;

    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

/* Gantt chart entry */
typedef struct {
    int time;
    int pid;
} GanttEntry;

/* Input */
void read_processes(Process[], int*);

/* Scheduling Algorithms */
void fcfs(Process[], int, GanttEntry[], int*);
void sjf(Process[], int, GanttEntry[], int*);
void srtf(Process[], int, GanttEntry[], int*);
void round_robin(Process[], int, int, GanttEntry[], int*);

/* Output */
void print_gantt(GanttEntry[], int);
void print_process_table(Process[], int);

#endif
