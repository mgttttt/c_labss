#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

union byte
{
  char c;
  unsigned bit1:1;
  unsigned bit2:7;
};

int main()
{
    char* str = (char *)calloc(100, sizeof(char));
    char* result = (char*)calloc(100, sizeof(char));
    char* buf = (char*)calloc(256, sizeof(char));
    union byte b;
    scanf("%s", str);
    int len = strlen(str), count = 0, flag = 0;
    int len_res = 0, buf_len = 0;
    char c;
    for (int i = 1; i < len; i++)
    {
        if (flag)
        {
            if (str[i] == str[i - 1])
                count++;
            else
            {
                b.bit1 = 1;
                b.bit2 = count;
                len_res = strlen(result);
                result[len_res++] = b.c;
                result[len_res++] = c;
                flag = 0;
                count = 0;
            }
        }
        else
        {
            if (str[i] == str[i - 1])
            {
                count += 2;
                c = str[i];
                flag = 1;
                if (buf_len)
                {
                  b.bit1 = 0;
                  b.bit2 = buf_len;
                  result[len_res++] = b.c;
                  strcat(result, buf);
                  buf[buf_len] = 0;
                  buf_len = 0;
                }
            }
            else
              buf[buf_len++] = str[i - 1];
        }
    }
    if (flag)
    {
      b.bit1 = 1;
      b.bit2 = count;
      len_res = strlen(result);
      result[len_res++] = b.c;
      result[len_res++] = c;
    }
    else if (buf_len)
    {
      buf[buf_len++] = str[len - 1];
      b.bit1 = 0;
      b.bit2 = buf_len;
      result[len_res++] = b.c;
      strcat(result, buf);
    }
    len_res = strlen(result);
    printf("%s\n", result);
    for (int i = 0; i < len_res; i++)
      printf("%hhu\n", result[i]);
    free(result);
    free(str);
    free(buf);
    return 0;
}
