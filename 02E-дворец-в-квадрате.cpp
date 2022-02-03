#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    int a, S, result = 0;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    input >> a >> S;
    a *= a;
    result = S - a;
    if (result < 0)
        result = -1;
    output << result;
    return 0;
}
