#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::fstream input, output;
    std::string color;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    input >> color;
    if (color == "GREEN")
        output << "YES";
    else
        output << "NO";
}