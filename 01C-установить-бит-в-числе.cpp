#include <iostream>

int main()
{
    int n, i;
    std::cin >> n >> i;
    n = n | (1 << i);
    std::cout << n << std::endl;
}
