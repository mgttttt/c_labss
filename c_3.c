#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)
int main() {
    float h;
    float x = 0;
    printf("Enter h: ");
    scanf("%f", &h);

    printf("x\t\tf(x)\n");
    printf("--------------------\n");

    do
    {
        if (x <= 1)
            printf("%f    %f\n", x, 8 * pow(x, 3) * cos(x));
        else
            printf("%f    %f\n", x, log(1 + sqrt(x)) - cos(x));
        x += h;
    } while (fabs(x - 2.0 - 2.0 * h) >= h);

    /*for (int i = 0; i <= 2 / h; i++)
    {
        if (x <= 1)
            printf("%f    %f\n", x, 8 * pow(x, 3) * cos(x));
        else
            printf("%f    %f\n", x, log(1 + sqrt(x)) - cos(x));
        x += h;
    }*/

    return 0;
}
