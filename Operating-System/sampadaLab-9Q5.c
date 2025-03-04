#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], p, i, st, len, j, c, k, a;

    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);

    printf("Enter blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }

    do {
        printf("Enter index starting block and length: ");
        scanf("%d%d", &st, &len);

        k = len;
        if (f[st] == 0) {
            for (j = st; j < (st + k); j++) {
                if (f[j] == 0) {
                    f[j] = 1;
                    printf("%d-------->%d\n", j, f[j]);
                } else {
                    printf("%d Block is already allocated\n", j);
                    k++;
                }
            }
        } else {
            printf("%d starting block is already allocated\n", st);
        }

        printf("Do you want to enter more file (Yes - 1 / No - 0): ");
        scanf("%d", &c);
    } while (c == 1);

    return 0;
}
