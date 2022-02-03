#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    char a[202];
    for (int i = 0; i <= 201; i++) {
        a[i] = '0';
    }
    for (int i = 0; i <= 201; i++) {
        input >> a[i];
        if ((int(a[i]) <  97 ) | (int(a[i]) >  122)) {
            break;
        }
        if ((int(a[i]) >= 97) & (int(a[i]) <= 119)) {
            a[i] = char(int(a[i]) + 3);
            output << a[i];
            continue;
        }
        if ((int(a[i]) >= 120) & (int(a[i]) <= 122)) {
            a[i] = char(int(a[i]) - 23);
            output << a[i];
            continue;
        }
        if ((int(a[i]) <  97 ) | (int(a[i]) >  122)) {
            break;
        }
    }
}