#include <iostream>
#include <fstream>

int main()
{
    std::fstream input,output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int N, X, Y, row = 1, column = 1;
    input >> N >> X >> Y;
    while (column < (N + 1)) {
        if (row % (N + 1) == 0) {
            output << "\n";
            column++;
            row = 1;
            continue;
        }
        if ((column == Y) & (row == X)) {
            output << "X";
            row++;
            continue;
        }
        if (column == Y) {
            output << "*";
            row++;
            continue;
        }
        if (row == X) {
            output << "*";
            row++;
            continue;
        }
        if (column % 2 != 0) {
            if (row % 2 != 0)
                output << "#";
            if (row % 2 == 0)
                output << ".";
            row++;
        }
        if (column % 2 == 0) {
            if (row % 2 != 0)
                output << ".";
            if (row % 2 == 0)
                output << "#";
            row++;
        }
    }
}
