#include <stdio.h>
#include <stdlib.h>

int main()
{
    int index = 0, size = 10, entoe, counter = 1;
    char *words = (char *)malloc(size);
    char ch;
    while ((int)ch != (char)10)
    {
        ch = getc(stdin);
        words[index] = ch;
        if (index == (size - 1))
        {
            size += 5;
            words = (char *)realloc(words, size);
        }
        if ((int)ch == 32)
        {
            counter++;
        }
        index++;
    }
    scanf("%d", &entoe);
    if (entoe > counter)
    {
        entoe = counter;
    }
    counter = 1;
    index = 0;
    while ((counter != (entoe + 1) & (int)words[index] != 10))
    {
        if ((int)words[index] == 32)
        {
            counter++;
            index++;
            continue;
        }
        if ((counter == entoe) & ((int)words[index] != 10))
        {
            printf("%c", words[index]);
        }
        index++;
    }
}