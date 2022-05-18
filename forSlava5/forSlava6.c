#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//функция заполнения массива
void fill(int * arr, int n)
{
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 101 - 50;
}

//функция вывода массива
void out(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%4d", arr[i]);
  printf("\n");
}

//под двойным циклом перебираем все возможные пары элементов
//если элементы совпадаю инкрементируем count
//возвращаем количество повторяющихся элементов
int find_count(int a[], int b[], int n1, int n2)
{
  int count = 0, flag = 0;
  for (int i = 0; i < n1; i++)
  {
    flag = 0;
    for (int j = 0; j < n2; j++)
    {
        for (int l = 0; l < i; l++)
          if (a[i] == a[l])
          {
            flag = 1;
            break;
          }
        if (flag) break;
        if (a[i] == b[j])
        {
          count++;
          break;
        }
    }
  }
  return count;
}

//снова имем совпадения, но сейчас уже записываем элементы в массив rep
void find_rep(int rep[], int a[], int b[], int n1, int n2)
{
  int count = 0, flag = 0;
  for (int i = 0; i < n1; i++)
  {
    flag = 0;
    for (int j = 0; j < n2; j++)
    {
      for (int l = 0; l < i; l++)
        if (a[i] == a[l])
        {
          flag = 1;
          break;
        }
      if (flag) break;
      if (a[i] == b[j])
      {
        rep[count++] = a[i];
        break;
      }
    }
  }
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
  //заполнение массивов
  fill(a, n1);
  fill(b, n2);
  //вывод массивов
  out(a, n1);
  out(b, n2);
  //ищем количество
  int count = find_count(a, b, n1, n2);
  //если count = 0 выводим сообщение, что повторяющихся элементов нет
  //иначе заполняем массив rep и выводим его
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

