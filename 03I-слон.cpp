#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int N, X, Y, row = 1, column = 1, cross = 0;
    input >> N >> X >> Y;
    int radiusX1 = X, radiusX2 = X,
        radiusY = Y;

    while (radiusY != 1) {
        radiusX1 += 1;
        radiusX2 -= 1;
        radiusY -= 1;
    }

    while (column <= N) {
        if (row % (N + 1) == 0) {
            column++;
            row = 1;
            radiusX1--;
            radiusX2++;
            radiusY ++;
            if (cross == 1) {
                radiusY--;
                cross = 0;
        }
            output << "\n";
            continue;
        }
        if ((row == X) & (column == Y)) {
            output << "X";
            row++;
            radiusY ++;
            cross = 1;
            continue;
        }
        if ((row == radiusX1) && (column == radiusY)) {
            output << "*";
            row++;
            continue;
        }
        if ((row == radiusX2) && (column == radiusY)) {
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

