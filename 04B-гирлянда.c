#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    int n, center, h = 0, w = 0, abs = 0, pos = 0;
    fscanf(input, "%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d", &a[i]);
        if (i == 0)
            h += a[i] * 2 + 1;
        else
            h += a[i] * 2 - 1;
        if ((a[i] * 2 + 1) > w)
            w = a[i] * 2 + 1;
    }
    center = (w - 1) / 2;
    char **garland = (char **)malloc(sizeof(char *) * h);
    for (int i = 0; i < h; i++)
    {
        garland[i] = (char *)malloc(sizeof(char) * w);
        for (int j = 0; j < w; j++)
            garland[i][j] = '.';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j >= 0; j--)
        {
            if (abs == 0)
            {
                if (i % 2 == 0)
                {
                    garland[pos          ][center] = (char)35;
                    garland[pos + (j * 2)][center] = (char)35;
                }
                else 
                {
                    garland[pos          ][center] = (char)42;
                    garland[pos + (j * 2)][center] = (char)42;
                }
            }
            else if (abs == a[i])
            {
                if (i % 2 == 0)
                {
                    garland[pos][center - abs] = (char)35;
                    garland[pos][center + abs] = (char)35;
                }
                else
                {
                    garland[pos][center - abs] = (char)42;
                    garland[pos][center + abs] = (char)42;
                }
            }
            else
            {
                if (i % 2 == 0)
                {
                    garland[pos          ][center - abs] = (char)35;
                    garland[pos          ][center + abs] = (char)35;
                    garland[pos + (j * 2)][center - abs] = (char)35;
                    garland[pos + (j * 2)][center + abs] = (char)35;
                }
                else
                {
                    garland[pos          ][center - abs] = (char)42;
                    garland[pos          ][center + abs] = (char)42;
                    garland[pos + (j * 2)][center - abs] = (char)42;
                    garland[pos + (j * 2)][center + abs] = (char)42;
                }
            }
            pos++;
            abs++;
        }
        pos += a[i] - 2;
        abs = 0;
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            fprintf(output, "%c", garland[i][j]);
        fprintf(output, "\n");
    }
}