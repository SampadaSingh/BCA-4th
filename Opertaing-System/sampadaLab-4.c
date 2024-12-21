#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    float AT, BT, WT, TAT, CT, remainingBT;
};

void inputProcesses(struct process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P[%d] Arrival Time: ", p[i].pid);
        scanf("%f", &p[i].AT);
        printf("P[%d] Burst Time: ", p[i].pid);
        scanf("%f", &p[i].BT);
        p[i].remainingBT = p[i].BT;
    }
}

void displayProcesses(struct process p[], int n) {
    float totalWT = 0, totalTAT = 0;
    printf("\n%-10s%-15s%-15s%-20s%-20s%-15s\n", "Process", "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time", "Waiting Time");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t\t%-15.2f%-15.2f%-20.2f%-20.2f%-15.2f\n", p[i].pid, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
        totalWT += p[i].WT;
        totalTAT += p[i].TAT;
    }
    printf("\nAverage TAT: %.2f\nAverage WT: %.2f\n", totalTAT / (float)n, totalWT / (float)n);
}

void FCFS(struct process p[], int n) {
    float currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].AT)
            currentTime = p[i].AT;
        p[i].CT = currentTime + p[i].BT;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        currentTime = p[i].CT;
    }
    displayProcesses(p, n);
}

void SJF(struct process p[], int n) {
    int completed = 0;
    float currentTime = 0;
    while (completed < n) {
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= currentTime && p[i].remainingBT > 0 && (minIndex == -1 || p[i].BT < p[minIndex].BT)) {
                minIndex = i;
            }
        }
        if (minIndex == -1) {
            currentTime++;
            continue;
        }
        currentTime += p[minIndex].BT;
        p[minIndex].CT = currentTime;
        p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
        p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
        p[minIndex].remainingBT = 0;
        completed++;
    }
    displayProcesses(p, n);
}

void SRTN(struct process p[], int n) {
    int completed = 0;
    float currentTime = 0;
    while (completed < n) {
        int minIndex = -1;
        int minRemainingTime = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].AT <= currentTime && p[i].remainingBT > 0) {
                if (p[i].remainingBT < minRemainingTime) {
                    minRemainingTime = p[i].remainingBT;
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1) {
            currentTime++;
            continue;
        }

        p[minIndex].remainingBT--;

        if (p[minIndex].remainingBT == 0) {
            completed++;
            p[minIndex].CT = currentTime + 1;
            p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
            p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
        }

        currentTime++;
    }

    displayProcesses(p, n);
}

void RR(struct process p[], int n, float timeQuantum) {
    float currentTime = 0;
    int completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remainingBT > 0 && p[i].AT <= currentTime) {
                if (p[i].remainingBT <= timeQuantum) {
                    currentTime += p[i].remainingBT;
                    p[i].remainingBT = 0;
                    p[i].CT = currentTime;
                    p[i].TAT = p[i].CT - p[i].AT;
                    p[i].WT = p[i].TAT - p[i].BT;
                    completed++;
                } else {
                    currentTime += timeQuantum;
                    p[i].remainingBT -= timeQuantum;
                }
            }
        }
        currentTime++;
    }
    displayProcesses(p, n);
}

void menu() {
    printf("\nChoose a scheduling algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Shortest Remaining Time Next (SRTN)\n");
    printf("4. Round Robin (RR)\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, n;
    float timeQuantum;
    struct process p[10];

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of processes: ");
            scanf("%d", &n);
            inputProcesses(p, n);
            FCFS(p, n);
            break;
        case 2:
            printf("Enter number of processes: ");
            scanf("%d", &n);
            inputProcesses(p, n);
            SJF(p, n);
            break;
        case 3:
            printf("Enter number of processes: ");
            scanf("%d", &n);
            inputProcesses(p, n);
            SRTN(p, n);
            break;
        case 4:
            printf("Enter number of processes: ");
            scanf("%d", &n);
            inputProcesses(p, n);
            printf("Enter Time Quantum: ");
            scanf("%f", &timeQuantum);
            RR(p, n, timeQuantum);
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}