//worst-fit
#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int nb, nf, temp, i, j, worstIdx;

    printf("\nMemory Management Scheme - Worst Fit\n");
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter number of files: ");
    scanf("%d", &nf);

    printf("\nEnter block sizes:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter file sizes:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    for (i = 0; i < nf; i++) {
        temp = -1;
        worstIdx = -1;
        for (j = 0; j < nb; j++) {
            if (!bf[j] && b[j] >= f[i] && b[j] - f[i] > temp) {
                temp = b[j] - f[i];
                worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            bf[worstIdx] = 1;
            ff[i] = worstIdx;
            frag[i] = temp;
        } else {
            ff[i] = -1;
        }
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1)
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("%d\t%d\t\tNot Allocated\t-\t\t-\n", i + 1, f[i]);
    }

    return 0;
}
