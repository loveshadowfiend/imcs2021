#include <iostream>
#include <fstream>
#include <vector>

int main() {
    using namespace std;
    ifstream input("input.txt");
    ofstream output("output.txt");
    vector<int> a(101, 0);
    int n, ans = 0, counter = 0;
    input >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        input >> x >> y;
        for (int j = x-y; j < x+y; j++) {
            if (j < 0 | j > 100) {
                continue;
            }
            a[j]++;
        }
    }
    for (int i : a) {
        if (i > ans) {
            ans = i;
        }
    }
    output << ans;
}
