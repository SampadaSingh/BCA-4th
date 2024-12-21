//Write a program to find the root of the following equation using the False Position method y = x - e-x
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x - exp(-x);
}

int main() {
    double xl, xu;
    int maxIter;

    printf("Enter the value of xl: ");
    scanf("%lf", &xl);
    printf("Enter the value of xu: ");
    scanf("%lf", &xu);
    printf("Enter the number of iterations: ");
    scanf("%d", &maxIter);

    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Iter", "xl", "xu", "xm", "f(xl)", "f(xu)", "f(xm)");

    for (int i = 0; i < maxIter; i++) {
        double xm = xu - (f(xu) * (xl - xu)) / (f(xl) - f(xu));
        double xmAns = f(xm);
        double xlAns = f(xl);
        double xuAns = f(xu);

        printf("%-10d %-10.4lf %-10.4lf %-10.4lf %-10.4lf %-10.4lf %-10.4lf\n", i + 1, xl, xu, xm, xlAns, xuAns, xmAns);

        if (xmAns < 0) {
            xl = xm;
        } else {
            xu = xm;
        }
    }

    double xm = xu - (f(xu) * (xl - xu)) / (f(xl) - f(xu));
    printf("\nThe root of the equation is approximately: %.4lf\n", xm);

    return 0;
}