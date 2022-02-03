#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    int A, B;
    input.open("input.txt", std::ios::in);
    input >> A >> B;
    output.open("output.txt", std::ios::out);
    output << A + B;
}