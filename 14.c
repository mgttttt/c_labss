#include <stdio.h>
#include <stdlib.h>
#define SZ 50
#pragma warning(disable:4996)
void add(unsigned short current_sum[], unsigned short cpy_current_sum[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        current_sum[i] += cpy_current_sum[i];
        if (current_sum[i] > 9)
            for (int j = i; j >= 0; j--)
            {
                if (current_sum[j] > 9)
                {
                    current_sum[j] %= 10;
                    current_sum[j - 1]++;
                }
            }
    }
}

void copy(unsigned short a[], unsigned short b[], int n)
{
    while (n)
    {
        n--;
        a[n] = b[n];
    }
}

void out(unsigned short a[], int n)
{
    int count = 0;
    while (!a[count]) count++;
    for (int i = count; i < SZ; i++)
        printf("%hu", a[i]);
}

int main()
{
    int n;
    unsigned short sum[SZ] = {0};
    unsigned short current_sum[SZ] = {0};
    unsigned short cpy_current_sum[SZ] = {0};

    current_sum[SZ - 1] = 1;
    sum[SZ - 1] = 1;

    printf("Enter number of field: ");
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++)
    {
        copy(cpy_current_sum, current_sum, SZ);
        add(current_sum, cpy_current_sum, SZ);
        add(sum, current_sum, SZ);
    }
    printf("sum: ");
    out(sum, SZ);
    printf("\ncount: ");
    out(current_sum, SZ);

    return 0;
}
