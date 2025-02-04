#include<stdio.h>

struct process{
    int pid, AT, BT, TAT, WT;
};

int main() {
int n, i;
float avg_WT = 0.0;
float avg_TAT = 0.0;
printf("Enter the number of processes: ");
scanf("%d", &n);

struct process pro[n];
    
for(i = 0; i < n; i++) {
pro[i].pid = i + 1;
printf("Enter Arrival Time (AT) and Burst Time (BT) for process %d: ", pro[i].pid);
scanf("%d%d", &pro[i].AT, &pro[i].BT);
}

pro[0].WT = 0;
pro[0].TAT = pro[0].BT;
printf("\nProcess Details:\n");
printf("Process ID: %d\n", pro[0].pid);
printf("Arrival Time (AT): %d and Burst Time (BT): %d\n", pro[0].AT, pro[0].BT);
printf("Wait Time = 0\n");
printf("Turn Arround Time = %d\n",pro[0].TAT);
avg_TAT += pro[0].TAT;

for(i = 1; i < n; i++) {
printf("Process ID: %d\n", pro[i].pid);
printf("Arrival Time (AT): %d and Burst Time (BT): %d\n", pro[i].AT, pro[i].BT);
pro[i].WT = pro[i-1].WT + pro[i-1].BT;
pro[i].TAT = pro[i].WT + pro[i].BT;
avg_WT += pro[i].WT;
avg_TAT += pro[i].TAT;

printf("Wait Time = %d\n",pro[i].WT);
printf("Turn Arround Time = %d\n",pro[i].TAT);
}
avg_WT = avg_WT/n;
avg_TAT = avg_TAT/n;
printf("avg WT: %f",avg_WT);
printf("avg TAT: %f",avg_TAT);
return 0;
}





