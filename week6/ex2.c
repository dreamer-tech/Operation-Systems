#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


struct Node {
    int AT, BT, index;
};


int main() {

    int process_number, arrival_time, burst_time, avg_tat, avg_wt, last_time, i, j;
    avg_tat = 0;
    avg_wt = 0;
    last_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &process_number);

    struct Node arr[process_number];

    for (i = 0; i < process_number; i++) {
        printf("Enter the arrival time and burst time: ");
        scanf("%d %d", &arrival_time, &burst_time);
        arr[i].AT = arrival_time;
        arr[i].BT = burst_time;
        arr[i].index = i + 1;
    }

    // sort processes by BT
    for (i = 0; i < process_number; i++) {
        for (j = i + 1; j < process_number; j++) {
            if (arr[i].BT > arr[j].BT) {
                struct Node cur = arr[i];
                arr[i] = arr[j];
                arr[j] = cur;
            }
        }
    }

    for (i = 0; i < process_number; i++) {

        // completion time (CT = ET)
        // turn around time = ET (Exit time) - AT
        // waiting time = TAT - BT = ET - AT - BT

        arrival_time = arr[i].AT;
        burst_time = arr[i].BT;

        int start_exec_time = __max(arrival_time, last_time);
        int exit_time = start_exec_time + burst_time;
        int turnaround_time = exit_time - arrival_time;
        int waiting_time = exit_time - arrival_time - burst_time;

        printf("For process %d:\n", arr[i].index);
        printf("CT = %d\n", exit_time);
        printf("TAT = %d\n", turnaround_time);
        printf("WT = %d\n", waiting_time);

        avg_tat += turnaround_time;
        avg_wt += waiting_time;
        last_time = exit_time;
    }
    printf("\n");
    printf("Average Turnaround Time: %d\n", avg_tat / process_number);
    printf("Average Waiting Time: %d\n", avg_wt / process_number);
    return 0;
}
