#include <stdio.h>
#include <math.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    double xA, yA, xB, yB, xO, yO, beta;
    fscanf(input, "%lf %lf %lf %lf %lf %lf %lf", &xA, &yA, &xB, &yB, &xO, &yO, &beta);
    double x1 = -sin(beta * M_PI / 180) * (yA - yO) + cos(beta * M_PI / 180) * (xA - xO) + xO,
           y1 =  cos(beta * M_PI / 180) * (yA - yO) + sin(beta * M_PI / 180) * (xA - xO) + yO,
           x2 = -sin(beta * M_PI / 180) * (yB - yO) + cos(beta * M_PI / 180) * (xB - xO) + xO,
           y2 =  cos(beta * M_PI / 180) * (yB - yO) + sin(beta * M_PI / 180) * (xB - xO) + yO;
    fprintf(output, "%0.3lf %0.3lf %0.3lf %0.3lf", x1, y1, x2, y2);
}
