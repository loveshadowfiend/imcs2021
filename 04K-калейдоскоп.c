#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    int n, counter = 0;
    fscanf(input, "%d", &n);
    int rows = n * 2 + 3,
        columns = n * 2 + 3,
        size = 1,
        sep1 = 0, sep2 = columns / 2, sep3 = columns - 1;
    char **chars = (char **)malloc(sizeof(char *) * (n + 1));
    char strings[(n + 1) * 2][n * 2];
    char newline;
    newline = getc(input);
    for (int i = 0; i < n; i++)
    {
        chars[i] = (char *)malloc(sizeof(char) * (n * 2));
        for (int j = 0; j < size; j++)
        {
            chars[i][j] = fgetc(input);
            if (j == 0)
            {
                strings[0][i] = chars[i][j];
                strings[0][((n * 2) - 1) - i] = chars[i][j];
            }
        }
        newline = fgetc(input);
        if (size < n)
            size++;
    }
    size = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= size)
            {
                strings[i + 1][j] = chars[j][i + 1];
                strings[i + 1][((n * 2) - 1) - j] = chars[j][i + 1];
            }
            else
            {
                strings[i + 1][j] = chars[i][j];
                strings[i + 1][((n * 2) - 1) - j] = chars[i][j];
            }
        }
        size++;
    }
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (sep1 == sep2)
                fprintf(output, "%c", (char)35);
            else if ((j == sep1) || (j == sep2) || (j == sep3))
                fprintf(output, "%c", (char)35);
            else
            {
                fprintf(output, "%c", strings[i][counter]);
                counter++;
            }
        }
        fprintf(output, "\n");
        counter = 0;
        sep1++;
        sep3--;
    }
    for (int i = n; i >= 0; i -= 1)
    {
        for (int j = 0; j < rows; j++)
        {
            if ((j == sep1) || (j == sep2) || (j == sep3))
                fprintf(output, "%c", (char)35);
            else
            {
                fprintf(output, "%c", strings[i][counter]);
                counter++;
            }
        }
        fprintf(output, "\n");
        counter = 0;
        sep1++;
        sep3--;
    }
}
