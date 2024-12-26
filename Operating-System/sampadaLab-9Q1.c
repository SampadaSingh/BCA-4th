#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int sum = 0, product = 0;
    int n, i, j;

    printf("Enter any two numbers: ");
    scanf("%d %d", &i, &j);

    n = fork();

    if (n > 0) {
        printf("Parent process\n");
        sum = i + j;
        printf("Sum of two numbers: %d\n", sum);
    } else {
        printf("Child process\n");
        product = i * j;
        printf("Product of two numbers: %d\n", product);
    }

    return 0;
}
