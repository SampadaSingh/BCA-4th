//best-fit
#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int nb, nf, temp, lowest;
    
    printf("\nMemory Management Scheme - Best Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (int i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files:\n");
    for (int i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    for (int i = 0; i < nf; i++) {
        lowest = 10000;
        for (int j = 0; j < nb; j++) {
            if (!bf[j] && (temp = b[j] - f[i]) >= 0 && temp < lowest) {
                ff[i] = j;
                lowest = temp;
            }
        }
        if (lowest != 10000) {
            frag[i] = lowest;
            bf[ff[i]] = 1;
        } else {
            ff[i] = -1; 
        }
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (int i = 0; i < nf; i++) {
        if (ff[i] != -1)
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("\n%d\t%d\t\tNot Allocated\t-\t\t-", i + 1, f[i]);
    }

    return 0;
}
