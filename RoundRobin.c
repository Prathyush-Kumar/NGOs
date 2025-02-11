#include <stdio.h>

struct process {
    int pid, AT, BT, remaining_BT, WT, TAT;
};

void roundRobin(struct process pro[], int n, int quantum) {
    int time = 0, remaining_processes = n;
    
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (pro[i].remaining_BT > 0) {
                int execution_time;
               
                if (pro[i].remaining_BT > quantum) {
                    execution_time = quantum;
                } else {
                    execution_time = pro[i].remaining_BT;
                }
                
                pro[i].remaining_BT -= execution_time;
                time += execution_time;
                
                if (pro[i].remaining_BT == 0) {
                    pro[i].TAT = time - pro[i].AT;
                    pro[i].WT = pro[i].TAT - pro[i].BT;
                    remaining_processes--;
                }
            }
        }
    }
}

int main() {
    int n, quantum;
    float avg_WT = 0.0, avg_TAT = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    struct process pro[n];

    for (int i = 0; i < n; i++) {
        pro[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", pro[i].pid);
        scanf("%d%d", &pro[i].AT, &pro[i].BT);
        pro[i].remaining_BT = pro[i].BT;
    }

    roundRobin(pro, n, quantum);

    printf("\nProcess Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: AT = %d, BT = %d, WT = %d, TAT = %d\n", 
                pro[i].pid, pro[i].AT, pro[i].BT, pro[i].WT, pro[i].TAT);
        avg_WT += pro[i].WT;
        avg_TAT += pro[i].TAT;
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_WT / n);
    printf("Average Turnaround Time: %.2f\n", avg_TAT / n);

    return 0;
}

