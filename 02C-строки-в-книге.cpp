#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    input.open("a.in", std::ios::in);
    output.open("a.out", std::ios::out);
    int perPage, num, page = 1;
    input >> perPage >> num;
    if (num <= perPage)
        page = 1;
    else {
        while (num > perPage) {
            num -= perPage;
            page += 1;
        }
    }
    output << page << " " << num << std::endl;
    return 0;
}