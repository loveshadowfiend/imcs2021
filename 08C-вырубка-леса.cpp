#include <iostream>
#include <fstream>

int main() {
    std::ifstream input("forest.in");
    std::ofstream output("forest.out");
    uint64_t a, k, b, m, x;
    input >> a >> k >> b >> m >> x;
    uint64_t i = 0, j = 2 * x / (a + b) + 1;
    while (i + 1 < j) {
        uint64_t mid = i + (j - i) / 2;
        if (((mid - mid / k) * a + (mid - mid / m) * b) < x) {
            i = mid;
        } else {
            j = mid;
        }
    }
    output << j;
}

