#include <iostream>
#include <fstream>
#include <math.h>

int main()
{
    std::fstream input, output;
    input .open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    float x1, y1, x2, y2, x, y, 
          distance1, distance2,
          distance3, distance4,
          distance;
    input >> x1 >> y1 >> x2 >> y2 >> x >> y;
    float x3 = x1, y3 = y2, x4 = x2, y4 = y1,
          centerX = (x1 + x2) / 2, 
          centerY = (y1 + y2) / 2;

    distance1 = pow(pow((x - x1     ), 2) + pow((y - y1     ), 2), 0.5);
    distance2 = pow(pow((x - x2     ), 2) + pow((y - y2     ), 2), 0.5);
    distance3 = pow(pow((x - x3     ), 2) + pow((y - y3     ), 2), 0.5);
    distance4 = pow(pow((x - x4     ), 2) + pow((y - y4     ), 2), 0.5);
    distance  = pow(pow((x - centerX), 2) + pow((y - centerY), 2), 0.5);

    if (distance1 < distance | 
        distance2 < distance | 
        distance3 < distance |
        distance4 < distance )
        {
        output << "CORNER";
        return 0;
        }

    if (distance1 >= distance | 
        distance2 >= distance | 
        distance3 >= distance |
        distance4 >= distance )
        {
        output << "CENTER";
        return 0;
        }
}
