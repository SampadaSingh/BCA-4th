// For LRU Page Replacement
#include <stdio.h>
int main()
{
    int num_pages, num_frames, page_faults = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    int pages[num_pages];
    printf("Enter the page reference string: ");
    for (int i = 0; i < num_pages; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);
    int frames[num_frames];

    for (int i = 0; i < num_frames; i++)
    {
        frames[i] = -1;
    }
    int least_recently_used_frame = 0;
    int least_recently_used_frame_index[num_frames];
    for (int i = 0; i < num_frames; i++)
    {
        least_recently_used_frame_index[i] = -1;
    }
    for (int i = 0; i < num_pages; i++)
    {
        int page = pages[i];
        int page_found = 0;
        for (int j = 0; j < num_frames; j++)
        {
            if (frames[j] == page)
            {
                page_found = 1;
                least_recently_used_frame_index[j] = i;
                break;
            }
        }
        if (!page_found)
        {
            int lru_frame_index = 0;
            for (int j = 0; j < num_frames; j++)
            {
                if (least_recently_used_frame_index[j] < least_recently_used_frame_index[lru_frame_index])
                {
                    lru_frame_index = j;
                }
            }
            frames[lru_frame_index] = page;
            least_recently_used_frame_index[lru_frame_index] = i;
            page_faults++;
        }
    }

    printf("Total page faults using LRU algorithm: %d\n", page_faults);
    return 0;
}
