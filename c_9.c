#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_pallindrom(char * str)
{
  printf("%s\n", str);
  int len = strlen(str);
  for(int i = 0; i < len / 2; i++)
    if (str[i] != str[len - 1 - i]) return 0;
  printf("%s\n", str);
  return len;
}

int main() {
  int temp;
  char * result = malloc(sizeof(char) * 100);
  char * str = malloc(sizeof(char) * 100);
  printf("%s", "Enter string: ");
  fgets(str, 100, stdin);
  char delim[] = ", ";
  char *p = strtok(str, delim);
  temp = is_pallindrom(p);
  if (temp && temp > strlen(result))
    result = p;
  while((p = strtok(NULL, delim)) != NULL)
  {
    printf("%s\n", p);
    temp = is_pallindrom(p);
    if (temp && temp > strlen(result))
      result = p;
  }
  if (strlen(result) == 0) printf("There are no pallindroms\n");
  else printf("%s\n", result);
  return 0;
}
