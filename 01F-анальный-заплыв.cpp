#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    float N, M, speed = 0;
    int L, K, seconds = 0, meters = 0;
    input >> N >> M >> K >> L;
    // std::cin >> N >> M >> K >> L;
    speed = (N / M);
    seconds = L * 60;
    while (seconds > M)
    {
        meters += N;
        seconds = seconds - M - K;
    }
    if (seconds > 0)
        meters += int(speed * seconds);
    output << int(meters) << std::endl;
    // std::cout << meters << std::endl;
    return 0;
}

