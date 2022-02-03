#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, input2, output;
    input.open("input.txt", std::ios::in);
    input2.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int N, mark, result = 0;
    char pass;
    input >> N;
    input2 >> N;
    for (int i = 0; i < N; i++) {
        input >> mark;
    }
    for (int i = 0; i < N; i++) {
        input >> pass;
        for (int j = 0; j < N; i++) {
            input2 >> mark;
            if (int(pass) == 43)
                result += mark;
            break;
        }
    }
    output << result;
}