//Write a program to find the root of the following equation using the Newton Raphson method y = x - e-x

#include <stdio.h>
#include <math.h>

double f(double x) {
    return x - exp(-x);
}

double df(double x) {
    return 1 + exp(-x);
}

int main() {
    double x0;
    int maxIter;

    printf("Enter the value of x0: ");
    scanf("%lf", &x0);
    printf("Enter the number of iterations: ");
    scanf("%d", &maxIter);

    printf("\n%-10s %-10s %-10s %-10s %-10s\n", "Iter", "x0", "f(x0)", "f'(x0)", "x1");

    for (int i = 0; i < maxIter; i++) {
        double x1 = x0 - f(x0) / df(x0);

        printf("%-10d %-10.4lf %-10.4lf %-10.4lf %-10.4lf\n", i + 1, x0, f(x0), df(x0), x1);

        x0 = x1;
    }

    printf("\nThe root of the equation is approximately: %.4lf\n", x0);

    return 0;
}
