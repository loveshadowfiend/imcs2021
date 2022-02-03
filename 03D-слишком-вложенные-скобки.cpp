#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream input, input2, output;
    input.open("input.txt", std::ios::in);
    input2.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int N, limit, counter = 0, reznya;
    char skobka, nextSkobka;
    std::string skobki;
    input >> N;
    std::getline(input, skobki);
    std::getline(input, skobki);
    limit = skobki.length();
    input.close();
    input.open("input.txt", std::ios::in);
    input >> N;
    input2 >> N;
    input2 >> nextSkobka;
    for (int i = 0; i < limit;i++) {
        input >> skobka;
        input2 >> nextSkobka;
        if (counter < N) {
            output << skobka;
            reznya = 0;
        }
        else
            reznya = 1;
        if (int(skobka) == 40)
            counter++;
        if (int(skobka) == 41)
            counter--;
        if ((counter == (N - 1)) & (reznya == 1))
            output << skobka;
    }
}
