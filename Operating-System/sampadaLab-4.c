#include <stdio.h>
#include <stdlib.h>

struct process{
    int pid, AT, BT, WT, TAT;
};

struct process a[10];

int queue[100];
int front = -1;
int rear = -1;

void inputArrivalTime(int n, int *arrivalTime);
void inputBurstTime(int n, int *burstTime, int *p);
void swap(int *x, int *y);
void sortingFCFS(int *p, int n, int *arrivalTime, int *burstTime);
void sortingSJF(int n, int *at, int *bt, int *p);
float calculateAvgTATime(int *TATime, int n);
float calculateAvgWaitingTime(int *WaitingTime, int n);
void FCFS(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p);
void SJF(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p);
void SRTN(int n);
void insert(int n);
int delete();
void RR(int n);

int main(){
    int choice;

    while (1)
    {
        printf("\nProcess scheduling algorithm: \n");
        printf("1. First Come First Serve \n");
        printf("2. Shortest Job First (non-preemptive) \n");
        printf("3. Shortest Remaining Time Next(preemptive) \n");
        printf("4. Round Robin \n");
        printf("5. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int n;
        float avgWaiting, avgTA;

        if (choice == 5)
        {
            printf("Terminating program!!\n");
            exit(0);
        }

        printf("Enter the number of process: ");
        scanf("%d", &n);

        int *arrivalTime = malloc(n * sizeof(int));
        int *burstTime = malloc(n * sizeof(int));
        int *waitingTime = malloc(n * sizeof(int));
        int *TATime = malloc(n * sizeof(int));
        int *Process = malloc(n * sizeof(int));

        switch (choice){
        case 1:
            printf(" >>>>First Come First Serve<<<<\n");
            printf("Number of process: %d\n", n);
            printf("Enter the arrival time: ");
            inputArrivalTime(n, arrivalTime);
            printf("Enter the burst time: ");
            inputBurstTime(n, burstTime, Process);
            FCFS(n, TATime, arrivalTime, burstTime, waitingTime, Process);
            printf("============================================================\n");
            break;

        case 2:
            printf(" >>>>Shortest Job First (non-preemptive)<<<<\n");
            printf("Number of process: %d\n", n);
            printf("Enter the arrival time: ");
            inputArrivalTime(n, arrivalTime);
            printf("Enter the burst time: ");
            inputBurstTime(n, burstTime, Process);
            SJF(n, TATime, arrivalTime, burstTime, waitingTime, Process);
            printf("============================================================\n");
            break;

        case 3:
            printf(" >>>>Shortest Remaining Time Next (preemptive)<<<<\n");
            printf("Number of process: %d\n", n);
            SRTN(n);
            printf("============================================================\n");
            break;

        case 4:
            printf(" >>>>Round Robin<<<<\n");
            printf("Number of process: %d\n", n);
            RR(n);
            printf("============================================================\n");
            break;

        default:
            printf("Please enter correct options!\n");
        }
    }
}

void inputArrivalTime(int n, int *arrivalTime){
    for (int i = 0; i < n; ++i)
        scanf("%d", &arrivalTime[i]);
}

void inputBurstTime(int n, int *burstTime, int *p){
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &burstTime[i]);
        p[i] = i + 1;
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortingFCFS(int *p, int n, int *arrivalTime, int *burstTime){
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arrivalTime[i] > arrivalTime[j]){
                swap(&p[i], &p[j]);
                swap(&arrivalTime[i], &arrivalTime[j]);
                swap(&burstTime[i], &burstTime[j]);
            }
        }
    }
}

float calculateAvgTATime(int *TATime, int n){
    float average, sum = 0;
    for (int i = 0; i < n; ++i){
        sum += TATime[i];
    }
    average = sum / n;
    return average;
}

float calculateAvgWaitingTime(int *WaitingTime, int n){
    float average, sum = 0;
    for (int i = 0; i < n; ++i){
        sum += WaitingTime[i];
    }
    average = sum / n;
    return average;
}

void sortingSJF(int n, int *at, int *bt, int *p){
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (at[i] > at[j]){
                swap(&p[i], &p[j]);
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            }else if (at[i] == at[j]){
                if (bt[i] > bt[j]){
                    swap(&p[i], &p[j]);
                    swap(&at[i], &at[j]);
                    swap(&bt[i], &bt[j]);
                }
            }
        }
    }
}

void FCFS(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p){
    int *completionTime = malloc(n * sizeof(int));
    int temp;

    sortingFCFS(p, n, arrivalTime, burstTime);

    completionTime[0] = arrivalTime[0] + burstTime[0];
    for (int i = 1; i < n; i++){
        temp = 0;
        if (completionTime[i - 1] < arrivalTime[i]){
            temp = arrivalTime[i] - completionTime[i - 1];
        }
        completionTime[i] = completionTime[i - 1] + burstTime[i] + temp;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    for (int i = 0; i < n; ++i){
        TATime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = TATime[i] - burstTime[i];
        printf("\nP[%d]\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d", p[i], arrivalTime[i], burstTime[i], completionTime[i], TATime[i], waitingTime[i]);
    }

    float avgWaiting = calculateAvgWaitingTime(waitingTime, n);
    float avgTA = calculateAvgTATime(TATime, n);
    printf("\nThe average waiting time is %.3f\n", avgWaiting);
    printf("The average Turnaround time is %.3f\n", avgTA);
}

void SJF(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p){
    int *completionTime = malloc(n * sizeof(int));
    int pos;
    int min = 1000;

    sortingSJF(n, arrivalTime, burstTime, p);

    completionTime[0] = arrivalTime[0] + burstTime[0];
    for (int i = 1; i < n; i++){
        for (int j = i; j < n; j++){
            if (arrivalTime[j] <= completionTime[i - 1]){
                if (burstTime[j] < min){
                    min = burstTime[j];
                    pos = j;
                }
            }
        }

        swap(&p[i], &p[pos]);
        swap(&arrivalTime[i], &arrivalTime[pos]);
        swap(&burstTime[i], &burstTime[pos]);
        min = 1000;
        completionTime[i] = completionTime[i - 1] + burstTime[i];
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    for (int i = 0; i < n; ++i){
        TATime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = TATime[i] - burstTime[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], arrivalTime[i], burstTime[i], completionTime[i], TATime[i], waitingTime[i]);
    }

    float avgWaiting = calculateAvgWaitingTime(waitingTime, n);
    float avgTA = calculateAvgTATime(TATime, n);
    printf("\nThe average waiting time is %.3f\n", avgWaiting);
    printf("The average Turnaround time is %.3f\n", avgTA);
}

void SRTN(int n){
    int *arrivalTime = malloc(n * sizeof(int));
    int *burstTime = malloc(n * sizeof(int));
    int *completionTime = malloc(n * sizeof(int));
    int *remainingTime = malloc(n * sizeof(int));
    int *waitingTime = malloc(n * sizeof(int));
    int *turnAroundTime = malloc(n * sizeof(int));
    int *p = malloc(n * sizeof(int));

    printf("Enter arrival times: ");
    for (int i = 0; i < n; ++i){
        scanf("%d", &arrivalTime[i]);
    }

    printf("Enter burst times: ");
    for (int i = 0; i < n; ++i){
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
        p[i] = i + 1;
    }

    int time = 0, count = 0, minIndex = -1;
    while (count < n){
        int minTime = 1000;
        for (int i = 0; i < n; ++i){
            if (arrivalTime[i] <= time && remainingTime[i] > 0 && remainingTime[i] < minTime){
                minTime = remainingTime[i];
                minIndex = i;
            }
        }

        if (minIndex != -1){
            remainingTime[minIndex]--;
            time++;

            if (remainingTime[minIndex] == 0){
                count++;
                completionTime[minIndex] = time;
                turnAroundTime[minIndex] = completionTime[minIndex] - arrivalTime[minIndex];
                waitingTime[minIndex] = turnAroundTime[minIndex] - burstTime[minIndex];
            }
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    for (int i = 0; i < n; ++i){
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], arrivalTime[i], burstTime[i], completionTime[i], turnAroundTime[i], waitingTime[i]);
    }

    float avgWaiting = calculateAvgWaitingTime(waitingTime, n);
    float avgTA = calculateAvgTATime(turnAroundTime, n);
    printf("\nThe average waiting time is %.3f\n", avgWaiting);
    printf("The average Turnaround time is %.3f\n", avgTA);

    free(arrivalTime);
    free(burstTime);
    free(completionTime);
    free(remainingTime);
    free(waitingTime);
    free(turnAroundTime);
}

void RR(int n){
    int *arrivalTime = malloc(n * sizeof(int));
    int *burstTime = malloc(n * sizeof(int));
    int *waitingTime = malloc(n * sizeof(int));
    int *turnAroundTime = malloc(n * sizeof(int));
    int *p = malloc(n * sizeof(int));
    int quantum;

    printf("Enter arrival times: ");
    for (int i = 0; i < n; ++i){
        scanf("%d", &arrivalTime[i]);
    }

    printf("Enter burst times: ");
    for (int i = 0; i < n; ++i){
        scanf("%d", &burstTime[i]);
        p[i] = i + 1;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int *remainingTime = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i){
        remainingTime[i] = burstTime[i];
    }

    int time = 0, count = 0;
    while (count < n){
        int flag = 0;
        for (int i = 0; i < n; ++i){
            if (remainingTime[i] > 0){
                flag = 1;
                if (remainingTime[i] > quantum){
                    time += quantum;
                    remainingTime[i] -= quantum;
                }else{
                    time += remainingTime[i];
                    remainingTime[i] = 0;
                    turnAroundTime[i] = time - arrivalTime[i];
                    waitingTime[i] = turnAroundTime[i] - burstTime[i];
                    count++;
                }
            }
        }
        if (!flag)
            break;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time");
    for (int i = 0; i < n; ++i){
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[i], arrivalTime[i], burstTime[i], turnAroundTime[i], waitingTime[i]);
    }

    float avgWaiting = calculateAvgWaitingTime(waitingTime, n);
    float avgTA = calculateAvgTATime(turnAroundTime, n);
    printf("\nThe average waiting time is %.3f\n", avgWaiting);
    printf("The average Turnaround time is %.3f\n", avgTA);

    free(arrivalTime);
    free(burstTime);
    free(waitingTime);
    free(turnAroundTime);
    free(p);
    free(remainingTime);
}