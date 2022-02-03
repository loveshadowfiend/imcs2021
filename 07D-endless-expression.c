#include <cmath>
#include <stdio.h>

int main()
{
    double x;
    scanf("%lf", &x);
    x = cbrt(x + (cbrt(x + cbrt(x + cbrt(x + cbrt(x + cbrt(x + cbrt(x + cbrt(x + cbrt(x + cbrt(x)))))))))));
    printf("%lf", x);
}
