#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int main() {

    int process_number, arrival_time, burst_time, avg_tat, avg_wt, last_time, i;
    avg_tat = 0;
    avg_wt = 0;
    last_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &process_number);
    for (i = 1; i <= process_number; i++) {

        // I supppose here that we are given all processes and their times in an ordered way - AT_i <= AT_(i + 1)
        // If it's not the truth then we will have to sort them by AT

        // completion time (CT = ET)
        // turn around time = ET (Exit time) - AT
        // waiting time = TAT - BT = ET - AT - BT

        printf("Enter the arrival time and burst time: ");
        scanf("%d %d", &arrival_time, &burst_time);

        int start_exec_time = __max(arrival_time, last_time);
        int exit_time = start_exec_time + burst_time;
        int turnaround_time = exit_time - arrival_time;
        int waiting_time = exit_time - arrival_time - burst_time;

        printf("For process %d:\n", i);
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
