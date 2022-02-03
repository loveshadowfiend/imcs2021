#include <stdio.h>
#include <stdlib.h>

int sort(int *a, int size);
int equalOne(int *a, int size);

int main()
{
    int n, s, counter = 0;
    scanf("%d %d", &n, &s);
    int *a = malloc(s * sizeof(int));
    for (int i = 0; i < s; i++)
        scanf("%d", &a[i]);
    sort(a, s);
    if (n == 0)
        printf("0");
    else if ((a[0] >= n) || (a[s - 1] == 0))
        printf("1");
    else if (equalOne(a, s) == 1)
        printf("%d", n);
    else
    {
        while (n != 0)
        {
            n /= a[0];
            counter++;
            for (int i = 0; i < s; i++)
            {
                if (n - a[i] == 0)
                {
                    n = 0;
                    counter++;
                }
            }
        }
        printf("%d", counter);
    }
}

int sort(int *a, int size)
{
    int counter = 0, temp;
    for (int i = 0; i < (size - 1); i++)
    {
        if (a[i] < a[i + 1])
        {
            counter++;
            temp = a[i + 1];
            a[i + 1] = a[i];
            a[i] = temp;
        }
        if ((counter == 0) & (i == (size - 2)))
        {
            break;
        }
        if (i == (size - 2))
        {
            counter = 0;
            i = -1;
        }
    }
    return *a;
}

int equalOne(int *a, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    if (sum == size)
        return 1;
    else
        return 0;
}