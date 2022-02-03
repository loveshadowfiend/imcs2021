#include <iostream>
#include <fstream>

int main()
{
    int a, b, c, result;
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    input >> a >> b >> c;
    result = (((((a >> 2) << 4) ^ b) << 1) | c) & 1073741823;
    output.open("output.txt", std::ios::out);
    output << result;
}
