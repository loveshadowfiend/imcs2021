#include <iostream>

int main()
{
    int M, K, P, Z, F, days;
    std::cin >> M >> K >> P >> Z >> F;
    days = M / (24 * K * F + 2 * K * P + 9 * K * Z);
    std::cout << days;
}