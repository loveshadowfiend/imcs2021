#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int n, max = 0;
    fscanf(input, "%d", &n);
    int **a = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            fscanf(input, "%d", &a[i][j]);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n; j++)
            if (abs(a[i + 1][j] - a[i][j]) > max)
                max = abs(a[i + 1][j] - a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (abs(a[i][j + 1] - a[i][j]) > max)
                max = abs(a[i][j + 1] - a[i][j]);
    fprintf(output, "%d", max);
}
