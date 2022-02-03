#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input;
    FILE *output;
    input = fopen("negative.in", "r");
    output = fopen("negative.out", "w");
    int n, m, counter = 0;
    fscanf(input, "%d %d", &n, &m);
    char **source = (char**)malloc(sizeof(char*) * n);
    char **edited = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
        source[i] = (char*)malloc(sizeof(char) * m);
    for (int i = 0; i < n; i++)
        edited[i] = (char*)malloc(sizeof(char) * m);
    for (int i = 0; i < n; i++)
        fscanf(input, "%s", source[i]);
    for (int i = 0; i < n; i++)
        fscanf(input, "%s", edited[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (source[i][j] == edited[i][j])
                counter++;
    fprintf(output, "%d", counter);
}