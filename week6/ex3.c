#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


struct Node {
    int AT, BT, index, tmp_BT;
};

struct AnsNode {
    int CT, TAT, WT;
};


int main() {

    int process_number, arrival_time, burst_time, avg_tat, avg_wt, last_time, i, j, quantum;
    avg_tat = 0;
    avg_wt = 0;
    last_time = 0;

    printf("Enter the quantum: ");
    scanf("%d", &quantum);

    printf("Enter the number of processes: ");
    scanf("%d", &process_number);

    struct Node arr[process_number];
    struct AnsNode result[process_number];

    for (i = 0; i < process_number; i++) {

        // I suppose here that AT_i <= AT_(i + 1) otherwise we should return the sort algorithm from ex2 to sort them by AT

        printf("Enter the arrival time and burst time: ");
        scanf("%d %d", &arrival_time, &burst_time);
        arr[i].AT = arrival_time;
        arr[i].BT = burst_time;
        arr[i].tmp_BT = burst_time;
        arr[i].index = i + 1;

    }

    int new_exec = 1;
    while (new_exec == 1) {

        new_exec = 0;

        // completion time (CT = ET)
        // turn around time = ET (Exit time) - AT
        // waiting time = TAT - BT = ET - AT - BT
        for (i = 0; i < process_number; i++) {

            if (arr[i].tmp_BT == 0) {
                continue;
            }

            if (arr[i].tmp_BT > quantum) {
                arr[i].tmp_BT -= quantum;
                new_exec = 1;
                continue;
            }

            arrival_time = arr[i].AT;
            burst_time = arr[i].BT;
            arr[i].tmp_BT = 0;

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

            new_exec = 1;
        }
    }
    printf("\n");
    printf("Average Turnaround Time: %d\n", avg_tat / process_number);
    printf("Average Waiting Time: %d\n", avg_wt / process_number);
    return 0;
}

// It shows the result as 2 previous ones.
// Its obvious as doesn't matter how we execute processes as we execute them sequentially, total execution time (sum of all burst times) is the same
// It can make sense to implement this strategy if there will several processes and I/O
