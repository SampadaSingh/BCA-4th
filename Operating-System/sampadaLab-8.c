#include <stdio.h>
#include <stdlib.h>

int abs(int x) {
    return x < 0 ? -x : x;
}

int fcfs(int requests[], int n, int head_start) {
    int head_movement = 0;
    int current_position = head_start;
    for (int i = 0; i < n; i++) {
        head_movement += abs(requests[i] - current_position);
        current_position = requests[i];
    }
    return head_movement;
}

int sstf(int requests[], int n, int head_start) {
    int head_movement = 0;
    int current_position = head_start;
    int processed[n];
    for (int i = 0; i < n; i++) processed[i] = 0;

    for (int i = 0; i < n; i++) {
        int min_distance = 1000, closest_request = -1;
        for (int j = 0; j < n; j++) {
            if (!processed[j] && abs(requests[j] - current_position) < min_distance) {
                min_distance = abs(requests[j] - current_position);
                closest_request = j;
            }
        }
        head_movement += min_distance;
        current_position = requests[closest_request];
        processed[closest_request] = 1;
    }
    return head_movement;
}

int scan(int requests[], int n, int head_start, int direction) {
    int head_movement = 0;
    int current_position = head_start;
    int sorted_requests[n + 2];
    int i, j, index = 0;

    for (i = 0; i < n; i++) sorted_requests[i] = requests[i];
    sorted_requests[n] = 0;
    sorted_requests[n + 1] = 199;
    n += 2;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (sorted_requests[i] >= current_position) {
            index = i;
            break;
        }
    }

    if (direction == 0) { 
        for (i = index - 1; i >= 0; i--) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
        head_movement += abs(current_position - 0);
        current_position = 0;
        for (i = index; i < n; i++) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
    } else {
        for (i = index; i < n; i++) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
        head_movement += abs(current_position - 199);
        current_position = 199;
        for (i = index - 1; i >= 0; i--) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
    }
    return head_movement;
}

int c_scan(int requests[], int n, int head_start) {
    int head_movement = 0;
    int current_position = head_start;
    int sorted_requests[n + 1];
    int i, j, index = 0;

    for (i = 0; i < n; i++) sorted_requests[i] = requests[i];
    sorted_requests[n] = 199;
    n += 1;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (sorted_requests[i] >= current_position) {
            index = i;
            break;
        }
    }

    for (i = index; i < n; i++) {
        head_movement += abs(sorted_requests[i] - current_position);
        current_position = sorted_requests[i];
    }
    head_movement += abs(current_position - 199);
    current_position = 0;
    for (i = 0; i < index; i++) {
        head_movement += abs(sorted_requests[i] - current_position);
        current_position = sorted_requests[i];
    }
    return head_movement;
}

int look(int requests[], int n, int head_start, int direction) {
    int head_movement = 0;
    int current_position = head_start;
    int sorted_requests[n];
    int i, j, index = 0;

    for (i = 0; i < n; i++) sorted_requests[i] = requests[i];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (sorted_requests[i] >= current_position) {
            index = i;
            break;
        }
    }

    if (direction == 0) { 
        for (i = index - 1; i >= 0; i--) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
        for (i = index; i < n; i++) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
    } else { 
        for (i = index; i < n; i++) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
        for (i = index - 1; i >= 0; i--) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
    }
    return head_movement;
}

int c_look(int requests[], int n, int head_start) {
    int head_movement = 0;
    int current_position = head_start;
    int sorted_requests[n];
    int i, j, index = 0;

    for (i = 0; i < n; i++) sorted_requests[i] = requests[i];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (sorted_requests[i] >= current_position) {
            index = i;
            break;
        }
    }

    for (i = index; i < n; i++) {
        head_movement += abs(sorted_requests[i] - current_position);
        current_position = sorted_requests[i];
    }
    if (index > 0) {
        head_movement += abs(current_position - sorted_requests[0]);
        current_position = sorted_requests[0];
        for (i = 0; i < index; i++) {
            head_movement += abs(sorted_requests[i] - current_position);
            current_position = sorted_requests[i];
        }
    }
    return head_movement;
}

int main() {
    int requests[] = {86, 147, 91, 177, 94, 150, 102, 175, 130};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head_start = 143;

    printf("Total head movement using FCFS: %d\n", fcfs(requests, n, head_start));
    printf("Total head movement using SSTF: %d\n", sstf(requests, n, head_start));
    printf("Total head movement using SCAN: %d\n", scan(requests, n, head_start, 0)); 
    printf("Total head movement using C-SCAN: %d\n", c_scan(requests, n, head_start));
    printf("Total head movement using LOOK: %d\n", look(requests, n, head_start, 0)); 
    printf("Total head movement using C-LOOK: %d\n", c_look(requests, n, head_start));

    return 0;
}
