#include <fstream>

int main() {
    using namespace std;
    ifstream input("diploma.in");
    ofstream output("diploma.out");
    uint64_t w, h, n;
    input >> w >> h >> n;
    uint64_t i = 0, j = 1e18;
    while (i + 1 < j) {
        uint64_t mid = i + (j - i) / 2,
                 ok = (mid / h) * (mid / w);
        if (ok < n) {
            i = mid;
        } else {
            j = mid;
        }
    }
    output << j;
}
