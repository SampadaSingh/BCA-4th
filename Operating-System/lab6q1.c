#include <stdio.h>

int main() {
    int no_of_frames, no_of_pages, frames[10], ref_string[30], temp[10];
    int flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    int flag = 0; // For hit: if flag = 1, then hit, else fault

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &ref_string[i]);
    }

    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    printf("\n===============================================================================\n");
    for (i = 0; i < no_of_frames; i++) {
        printf("frame[%d]\t", i);
    }
    printf("page fault");
    printf("\n===============================================================================\n");

    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == ref_string[i]) {
                flag1 = flag2 = 1;
                flag = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    faults++;
                    frames[j] = ref_string[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            flag3 = 0;
            for (j = 0; j < no_of_frames; ++j) {
                temp[j] = -1;
                for (k = i + 1; k < no_of_pages; ++k) {
                    if (frames[j] == ref_string[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j) {
                if (temp[j] == -1) {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0) {
                max = temp[0];
                pos = 0;
                for (j = 1; j < no_of_frames; ++j) {
                    if (temp[j] > max) {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = ref_string[i];
            faults++;
        }

        printf("\n");
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1)
                printf("%4d\t\t", frames[j]);
            else
                printf(" - \t\t");
        }

        if (flag == 0) {
            printf(" F");
        }
        flag = 0;
    }

    printf("\n===============================================================================\n");
    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
