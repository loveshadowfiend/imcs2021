#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    while (1) {
        if (n % 15 == 0) {
            std::cout << "FizzBuzz" << std::endl;
            break;
        }
        if (n % 3 == 0) {
            std::cout << "Fizz" << std::endl;
            break;
        }
        if (n % 5 == 0) {
            std::cout << "Buzz" << std::endl;
            break;
        }
        else {
            std::cout << "" << std::endl;
            break;
        }
    }
}
