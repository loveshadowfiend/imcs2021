#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int A, B, temp, counter = 1, maximum;
    input >> A >> B;
    if ((A + B - 1) % 4 == 0) {
        output << A + B - 1;
        return 0;
    }
    else {
        output << 0;
    }
}
