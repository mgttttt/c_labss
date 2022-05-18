#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//частотность строки
//заводим массив на 256 символов - каждый элемент это количество раз
//которое встретился элемент в строке
void get_frequency(char * str, char * freq, int n)
{
  for (int i = 0; i < n; i++)
    freq[(int)str[i]]++;
}

//сумма частотностей каждого символа в строке
int sum_of_freq(char * str, char * freq, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += freq[(int)str[i]];
  return sum;
}

//ищем слово с максимальной частотностью
//пробел и запятая это разделители
//с помощью функции strtok сплитим строку по заданным разделителям
//после каждого вызова функции strtok получаем слово, ищем сумму частотностей
//возвращается максимальная найденная частотность
int get_max_freq(char * str, char * freq, int n)
{
  char * delim = " ,\n";
  int max_freq = 0;
  char * p = strtok(str, delim);
  int frequency = sum_of_freq(p, freq, strlen(p));
  printf("frequency of word \"%s\":%d\n", p, frequency);
  if (frequency > max_freq)
    max_freq = frequency;
  while((p = strtok(NULL, delim)) != NULL)
  {
    frequency = sum_of_freq(p, freq, strlen(p));
    printf("frequency of word \"%s\":%d\n", p, frequency);
    if (frequency > max_freq)
      max_freq = frequency;
  }
  return max_freq;
}

int main ()
{
  char * delim = " ,\n";
  char * str = (char *)malloc(sizeof(char) * 256);
  char * freq = (char *)calloc(256, sizeof(char));//тут выделяем с помощью calloc чтобы сразу занулить все элементы
  char * str_cpy = (char *)malloc(sizeof(char) * 256);
  fgets(str, 255, stdin);
  strcpy(str_cpy, str);
  int len = strlen(str);
  get_frequency(str, freq, len); //считаем частотность
  int max_freq = get_max_freq(str, freq, len); //находим максимальную частотность
  char * p = strtok(str_cpy, delim); //опять сплитим по пробелам и запятым
  //если частотность слова не совпадает с максимальной, то выводим слово
  //иначе пропускаем слово, таким образом удаляем слова с максимальной частотностью
  if (sum_of_freq(p, freq, strlen(p)) != max_freq)
    printf("%s ", p);
  while((p = strtok(NULL, delim)) != NULL)
  {
    if (sum_of_freq(p, freq, strlen(p)) != max_freq)
      printf("%s ", p);
  }
  printf("\n");
  return 0;
}
