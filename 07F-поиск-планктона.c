#include <stdio.h>
#include <math.h>

int main() {
    double x0, xn, a, b;
    scanf("%lf %lf %lf %lf", &x0, &xn, &a, &b);
    double min = 1.7e308;
    for (int i = x0; i <= xn; i++) {
        double f = -0.0001 * pow(i, 4) + a * pow(i, 3) - 0.05 * pow(i, 2) + b * i + 50;
        if (f < min)
            min = f;
    }
    printf("%lf", min);
}
