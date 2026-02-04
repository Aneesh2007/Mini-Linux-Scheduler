#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_PROCESSES 20
#define MAX_GANTT 1000

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;

    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

typedef struct {
    int time;
    int pid;
} GanttEntry;
void print_gantt(GanttEntry[], int);
void print_process_table(Process[], int);
void sjf(Process[], int, GanttEntry[], int*);

#endif
