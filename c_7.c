#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fill(int m, int n, int array[][n])
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = rand() % 200 + 1;
}

void out(int m, int n, int arr[][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

double findNorm(int m, int n, int arr[][n])
{
    double result = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            result += pow(arr[i][j], 2);
    return sqrt(result);
}

int main() {
    srand(time(NULL));
    int n, m;
    printf("Enter count of rows: ");
    scanf("%d", &m);
    printf("Enter count of columns: ");
    scanf("%d", &n);
    int array[m][n];
    fill(m, n, array);
    out(m, n, array);
    printf("%lf\n", findNorm(m, n, array));
    return 0;
}
