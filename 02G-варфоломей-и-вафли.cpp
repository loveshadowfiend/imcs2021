#include <iostream>
#include <fstream>

int main()
{
    int A, B, K, floor = 0;
    std::cin >> A >> B >> K;
    while (A >= K && B >= K) {
        A -= K;
        floor++;
        B -= K;
        floor++;
    }
    if (A >= K || B >= K) {
        floor++;
    }
    std::cout << floor;
}
