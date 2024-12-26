#include <stdio.h>

int main() {
    int f[50], i, st, len, j, c, k, count = 0;

    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    printf("Files Allocated are:\n");

    do {
        count = 0;

        printf("\nEnter the starting block and length of the file: ");
        scanf("%d%d", &st, &len);

        for (k = st; k < (st + len); k++) {
            if (f[k] == 0) {
                count++;
            }
        }

        if (len == count) {
            for (j = st; j < (st + len); j++) {
                if (f[j] == 0) {
                    f[j] = 1;
                    printf("%d\t%d\n", j, f[j]);
                }
            }
            printf("The file is allocated to disk.\n");
        } else {
            printf("The file is not allocated.\n");
        }

        printf("Do you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}
