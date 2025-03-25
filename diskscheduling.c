#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate FCFS Disk Scheduling
void FCFS(int requests[], int n, int head) {
    int seek = 0;
    printf("\nFCFS Disk Scheduling:\n");
    for (int i = 0; i < n; i++) {
        seek += abs(requests[i] - head);
        printf("%d -> ", requests[i]);
        head = requests[i];
    }
    printf("\nTotal Seek Time: %d\n", seek);
}

// Function to calculate SSTF Disk Scheduling
void SSTF(int requests[], int n, int head) {
    int seek = 0, completed[n], min, index;
    for (int i = 0; i < n; i++) completed[i] = 0;
   
    printf("\nSSTF Disk Scheduling:\n");
    for (int i = 0; i < n; i++) {
        min = 9999;
        for (int j = 0; j < n; j++) {
            if (!completed[j] && abs(requests[j] - head) < min) {
                min = abs(requests[j] - head);
                index = j;
            }
        }
        seek += min;
        head = requests[index];
        completed[index] = 1;
        printf("%d -> ", head);
    }
    printf("\nTotal Seek Time: %d\n", seek);
}

int main() {
    int n, head;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++) scanf("%d", &requests[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
   
    FCFS(requests, n, head);
    SSTF(requests, n, head);
   
    return 0;
}
