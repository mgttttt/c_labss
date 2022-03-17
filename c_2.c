#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    double x;
    printf("Enter x {0.01 <= x <= 1.39} -> ");
    scanf("%lf", &x);
    if (x <= 1.39 && x >= 0.01)
    {
        double y = 5 * sqrt(sin(sqrt(x)));
        double z = log10(cos(log(y)));
        printf("y(x) = %lf\nz(y) = %lf\n", y, z);
    }
    else printf("value is incorrect!");

    return 0;
}
