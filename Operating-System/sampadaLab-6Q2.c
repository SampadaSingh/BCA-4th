// For FIFO Page Replacement
#include <stdio.h>

int main() {
    int no_of_frames, no_of_pages, frames[10], ref_string[30];
    int page_faults = 0;
    int is_page_found, pos;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");
    for (int i = 0; i < no_of_pages; ++i) {
        scanf("%d", &ref_string[i]);
    }

    for (int i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    printf("\n===============================================================================\n");
    printf("Step\t");
    for (int i = 0; i < no_of_frames; ++i) {
        printf("Frame[%d]\t", i);
    }
    printf("Page Fault\n");
    printf("===============================================================================\n");

    int front = 0;

    for (int i = 0; i < no_of_pages; ++i) {
        is_page_found = 0;

        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] == ref_string[i]) {
                is_page_found = 1;
                break;
            }
        }

        if (!is_page_found) {
            if (frames[front] == -1) {
                frames[front] = ref_string[i];
                page_faults++;
            } else {
                frames[front] = ref_string[i];
                page_faults++;
            }

            front = (front + 1) % no_of_frames;
        }

        printf("%d\t", i + 1);
        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1)
                printf("%4d\t\t", frames[j]);
            else
                printf(" - \t\t");
        }

        if (!is_page_found) {
            printf(" F");
        }
        printf("\n");
    }

    printf("===============================================================================\n");
    printf("Total Page Faults = %d\n", page_faults);

    return 0;
}
