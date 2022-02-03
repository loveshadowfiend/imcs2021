#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int N = 0, i = 0, sum = 0, num = 0;
    input >> N;
    for (i = 0; i < N; i++) {
        input >> num;
        sum += num;
    }
    output << sum;
}