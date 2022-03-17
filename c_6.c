#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void fill(int n, int array[])
{
    for (int i = 0; i < n; i++)
        array[i] = rand() % 200 + 1;
}

void out(int n, int arr[])
{
    for (int i = 0; i < n; i++)
        printf("%4d", arr[i]);
    printf("\n");
}

int isPrime(int n)
{
    if (n == 2) return 1;
    for (int i = 2; i <= sqrt(n); i++)
        if (!(n % i)) return 0;
    return 1;
}

int main() {
    srand(time(NULL));
    int n, count_of_primes = 0;
    printf("Enter count of elements: ");
    scanf("%d", &n);
    int array[n];
    int ind[n];
    fill(n, array);
    out(n, array);
    for (int i = 0; i < n; i++)
        if (isPrime(array[i]))
        {
            ind[count_of_primes] = i;
            count_of_primes++;
        }
    if (count_of_primes == 1)
        printf("%d", array[ind[0]]);
    else if (count_of_primes == 2)
    {
        int temp = array[ind[0]];
        array[ind[0]] = array[ind[1]];
        array[ind[1]] = temp;
        out(n, array);
    }
    else if (count_of_primes > 2)
        out(count_of_primes, ind);
    else printf("Primes count: 0");
    return 0;
}
