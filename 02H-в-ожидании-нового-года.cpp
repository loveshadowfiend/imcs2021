#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    int h, m;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    input >> h >> m;
    if (m > 0)
        h += 1;
    if (m == 0)
        m = 60;
    output << 24 - h << " " << 60 - m;
    return 0;
}