#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void fill(int m, int n, int *(array[n]))
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = rand() % 200 + 1;
}
void out(int m, int n, int *(arr[n]))
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void findSumInRows(int m, int n, int *(array[n]))
{
  int sum = 0;
  int max = -1E9, min = 1E9;
  int i_max, i_min;
  for (int i = 0; i < m; i++)
  {
      sum = 0;
      for (int j = 0; j < n; j++)
          sum += array[i][j];
      if (sum > max)
      {
          max = sum;
          i_max = i;
      }
      if (sum < min)
      {
          min = sum;
          i_min = i;
      }
  }
  printf("max sum: %d in row number: %d\nmin sum: %d in row number: %d\n", max, i_max, min, i_min);
}

void findSumInColumns(int m, int n, int *(array[n]))
{
  int sum = 0;
  int max = -1E9, min = 1E9;
  int j_max, j_min;
  for (int j = 0; j < n; j++)
  {
      sum = 0;
      for (int i = 0; i < m; i++)
          sum += array[i][j];
      if (sum > max)
      {
          max = sum;
          j_max = j;
      }
      if (sum < min)
      {
          min = sum;
          j_min = j;
      }
  }
  printf("max sum: %d in column number: %d\nmin sum: %d in column number: %d\n", max, j_max, min, j_min);
}

int main() {
    srand(time(NULL));
    int n, m;
    printf("Enter count of rows: ");
    scanf("%d", &m);//количество строк
    printf("Enter count of columns: ");
    scanf("%d", &n);//количество столбцов
    int **array = (int **)malloc(sizeof(int *) * m);
    if (!array)
    {
      printf("Memory allocation error!\n");
      exit(EXIT_FAILURE);
    }
    for (int i = 0; i < m; i++)
      array[i] = (int *)malloc(n * sizeof(int));
    fill(m, n, array);//заполняем массив
    out(m, n, array);//вывод массив
    findSumInRows(m, n, array);
    findSumInColumns(m, n, array);
    for (int i = 0; i < m; i++)
      free(array[i]);
    free(array);
    return 0;
}
