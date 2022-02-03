#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    float N, V1, V2, result1, result2;
    input >> N >> V1 >> V2;
    result1 = (N / (V1 + V2)) * V1;
    result2 = (N / (V1 + V2)) * V2;
    output << int(result1) << " " << int(result2);
    return 0;
}
