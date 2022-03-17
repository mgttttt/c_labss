#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double common_average(int n)
{
    int count_of_dg = 0;
    double result = 0;
    while (n)
    {
        result += n % 10;
        n /= 10;
        count_of_dg++;
    }
    return result / count_of_dg;
}

double rec_average(int n, int count)
{
    if (!n) return 1.0 / count;
    double sum = rec_average(n / 10, count + 1) + n % 10;
    return (int)sum / (1 / (sum - (int)sum));
}

int main() {
    int number;
    printf("Enter integer number: ");
    scanf("%d", &number);

    printf("Average sum of digits:\n");
    printf("Cycle: %lf\n", common_average(number));
    printf("Recursion: %lf\n", rec_average(number, 0));

    return 0;
}
