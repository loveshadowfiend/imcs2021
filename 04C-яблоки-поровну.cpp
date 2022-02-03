#include <iostream>
#include <fstream>

int main()
{
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    int a[3], maxim = 0, minim = 1001, x, y, z, goal;
    for (int i = 0; i < 3; i++) {
        input >> a[i];
    }
    if ( (a[0] == a[1]) & (a[1] == a[2]) ) {
        output << 0;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (a[i] < minim) {
            minim = a[i];
            y = i + 1;
        }
        if (a[i] > maxim) {
            maxim = a[i];
            x = i + 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        if ((a[i] != maxim) & (a[i] != minim)) {
            goal = a[i];
        }
    }
    if ( int(int(2) - float( (maxim + minim) / goal )) == 0 ) {
        z = maxim - goal;
        a[x - 1] -= z;
        a[y - 1] += z;
    }
    if ( (a[0] == a[1]) & (a[1] == a[2]) ) {
        output << x << " " << y << " " << z;
        return 0;
    }
    output << -1;
}