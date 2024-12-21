//Write a program to find the root of the following equation using the Bisection method y = x - e-x
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x - exp(-x);
}

int main() {
    double xl, xu;

    printf("Enter the value of xl: ");
    scanf("%lf", &xl);
    printf("Enter the value of xu: ");
    scanf("%lf", &xu);

    double xuAns = f(xu);
    double xlAns = f(xl);

    printf("\nInitial Values:\n");
    printf("f(xu) = %lf\n", xuAns);
    printf("f(xl) = %lf\n", xlAns);

    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "Iter", "xl", "xu", "xm", "f(xm)", "Interval");

    for (int i = 0; i < 10; i++) {
        double xm = (xl + xu) / 2.0;
        double xmAns = f(xm);

        printf("%-10d %-10.4lf %-10.4lf %-10.4lf %-10.4lf %-10.4lf\n", i + 1, xl, xu, xm, xmAns, xu - xl);

        if (xmAns < 0) {
            xl = xm;
        } else {
            xu = xm;
        }
    }

    double xm = (xl + xu) / 2.0;
    printf("\nThe root of the equation is approximately: %.4lf\n", xm);

    return 0;
}
