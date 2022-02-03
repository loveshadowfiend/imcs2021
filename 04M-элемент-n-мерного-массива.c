#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ullong;

ullong counter(ullong *a, ullong size, ullong start);

int main()
{
    int n;
    ullong result = 0;
    scanf("%d", &n);
    ullong *a = (ullong *)malloc(sizeof(ullong) * n);
    ullong *b = (ullong *)malloc(sizeof(ullong) * n);
    for (ullong i = 0; i < n; i++)
    {
        scanf("%llu", &a[i]);
    }
    for (ullong i = 0; i < n; i++)
    {
        scanf("%llu", &b[i]);
    }
    for (ullong i = 0; i < (n - 1); i++)
    {
        result += counter(a, n, i) * (b[i]);
    }
    result += b[n - 1];
    printf("%llu", result);
}

ullong counter(ullong *a, ullong size, ullong start)
{
    ullong count = 1;
    for (ullong i = start + 1; i < size; i++)
    {
        count *= a[i];
    }
    return count;
}