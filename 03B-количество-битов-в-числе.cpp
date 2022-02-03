#include <iostream>
#include <fstream>
#include <math.h>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int x, counter = 0, i = 0;
    input >> x;
    for (i = 0; i <= int(log2(x)); i++) {
        if (((x >> i) & 1) == 1)
            counter++;
    }
    output << counter;
}