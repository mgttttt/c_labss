#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)

double common_average(int n)
{
    int count_of_dg = 0;
    double result = 0;
    while (n > 0)
    {
        result += n % 10;
        n /= 10;
        count_of_dg++;
    }
    return result / count_of_dg;
}

double rec_average(int n)
{
    static int count_of_dg = 0;
    static double result = 0;
    result += n % 10;
    n /= 10;
    count_of_dg++;
    return (n > 0) ? rec_average(n) : result / count_of_dg;
}

int main() {
    int number;
    printf("Enter integer number: ");
    scanf("%d", &number);

    printf("Average sum of digits:\n");
    printf("Cicle: %lf \n", common_average(number));
    printf("Recursion: %lf", rec_average(number));

    return 0;
}
