#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill(int * arr, int n)
{
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 101 - 50;
}

void out(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%4d", arr[i]);
  printf("\n");
}

int find_count(int a[], int b[], int n1, int n2)
{
  int count = 0;
  for (int i = 0; i < n1; i++)
    for (int j = 0; j < n2; j++)
      if (a[i] == b[j])
        count++;
  return count;
}

void find_rep(int rep[], int a[], int b[], int n1, int n2)
{
  int count = 0;
  for (int i = 0; i < n1; i++)
    for (int j = 0; j < n2; j++)
      if (a[i] == b[j])
        rep[count++] = a[i];
}

int main()
{
  int n1, n2;
  srand(time(NULL));
  printf("Enter length of first array: ");
  scanf("%d", &n1);
  printf("Enter length of second array: ");
  scanf("%d", &n2);
  int a[n1], b[n2];
  fill(a, n1);
  fill(b, n2);
  out(a, n1);
  out(b, n2);
  int count = find_count(a, b, n1, n2);
  if (!count)
    printf("no repeating elements\n");
  else
  {
    int rep[count];
    find_rep(rep, a, b, n1, n2);
    out(rep, count);
  }
  return 0;
}
