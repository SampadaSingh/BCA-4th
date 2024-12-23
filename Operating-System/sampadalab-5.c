#include <stdio.h>
int main()
{
    int processes, resources;

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter number of resources: ");
    scanf("%d", &resources);

    int available[resources];

    printf("Enter the available resources:\t");

    for (int i = 0; i < resources; i++)
    {
        scanf("%d", &available[i]);
    }

    int max[processes][resources];
    int allocation[processes][resources];
    int need[processes][resources];

    printf("Enter the maximum resources for each process:\n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d:\t", i);
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d:\t", i);
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int work[resources];
    for (int i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    int finish[processes];
    for (int i = 0; i < processes; i++)
    {
        finish[i] = 0;
    }

    int safe_sequence[processes];
    int safe = 0;

    while (safe < processes)
    {
        int found = 0;
        for (int i = 0; i < processes; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < resources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == resources)
                {
                    found = 1;
                    for (int k = 0; k < resources; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safe_sequence[safe++] = i;
                    finish[i] = 1;
                }
            }
        }
        if (!found)
        {
            printf("Unsafe state!\n");
            return 1;
        }
    }

    printf("Safe sequence:");
    for (int i = 0; i < processes; i++)
    {
        printf(" %d", safe_sequence[i]);
    }
    printf("\n");
    return 0;
}