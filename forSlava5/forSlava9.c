#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_frequency(char * str, char * freq, int n)
{
  for (int i = 0; i < n; i++)
    freq[str[i]]++;
}

int sum_of_freq(char * str, char * freq, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += freq[str[i]];
  return sum;
}

int get_max_freq(char * str, char * freq, int n)
{
  int max_freq = 0;
  char * p = strtok(str, delim);
  int freq = sum_of_freq(p, freq, strlen(p));
  if (freq > max_freq)
    max_freq = freq;
  while((p = strtok(str, NULL)) != NULL)
  {
    int freq = sum_of_freq(p, freq, strlen(p));
    if (freq > max_freq)
      max_freq = freq;
  }
  return max_freq;
}

int main ()
{
  char delim = " ,";
  char * str = (char *)malloc(sizeof(char) * 256);
  char * freq = (char *)calloc(256, sizeof(char));
  char * str_cpy = (char *)malloc(sizeof(char) * 256);
  fgets(stdin, 255, str);
  strcpy(str_cpy, str);
  int len = strlen(str);
  get_frequency(str, freq, len);
  int max_freq = get_max_freq(str, freq, len);
  char * p = strtok(str_cpy, delim);
  if (sum_of_freq(p, freq, strlen(p)) != max_freq)
    printf("%s ", p);
  while((p = strtok(str_cpy, NULL)) != NULL)
  {
    if (sum_of_freq(p, freq, strlen(p)) != max_freq)
      printf("%s ", p);
  }
  return 0;
}
