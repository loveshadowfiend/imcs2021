#include <stdio.h>
#include <math.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    double xA, yA, x1, y1, x2, y2, min = 1.79769e+308;
    fscanf(input, "%lf %lf %lf %lf %lf %lf", &xA, &yA, &x1, &y1, &x2, &y2);
    for (int x = x1; x <= x2; x += (x2 - x1))
        for (int y = y1; y <= y2; y++)
            if (sqrt(pow(xA - x, 2) + pow(yA - y, 2)) < min)
                min = sqrt(pow(xA - x, 2) + pow(yA - y, 2));
    for (int x = x1; x <= x2; x++)
        for (int y = y1; y <= y2; y += (y2 - y1))
            if (sqrt(pow(xA - x, 2) + pow(yA - y, 2)) < min)
                min = sqrt(pow(xA - x, 2) + pow(yA - y, 2));
    fprintf(output, "%0.3lf", min);
}
