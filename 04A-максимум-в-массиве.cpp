#include <iostream>
#include <fstream>
#include <math.h>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int N, num, maxim = pow(-2, 31);
    input >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        input >> num;
        a[i] = num;
        if (num > maxim)
            maxim = num;
    }
    output << maxim;
}