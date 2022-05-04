#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
struct byte
{
    unsigned bit1 : 7;
    unsigned bit2 : 1;
};

union bt
{
    unsigned char c;
    struct byte byte;
};

char * add_nch(int n, char c, char * result)
{
    errno = 0;
    char * str = calloc(1, sizeof(char));
    if (errno)
    {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    sprintf(str, "%c", c);
    while (n)
    {
        strcat(result, str);
        n--;
    }
    return result;
}

char * code(char * str)
{
    char *result = (char *)calloc(256, sizeof(char));
    char *buf = (char *)calloc(256, sizeof(char));
    union bt b;
    int len = strlen(str), count = 0, flag = 0;
    int len_res = 0, buf_len = 0;
    char c;
    for(int i = 1; i < len; i++)
    {
        if(flag)
        {
            if(str[i] == str[i - 1])
                count++;
            else
            {
                b.byte.bit2 = 1;
                b.byte.bit1 = count;
                len_res = strlen(result);
                result[len_res++] = b.c;
                result[len_res++] = c;
                flag = 0;
                count = 0;
            }
        }
        else
        {
            if(str[i] == str[i - 1])
            {
                count += 2;
                c = str[i];
                flag = 1;
                if(buf_len)
                {
                    b.byte.bit2 = 0;
                    b.byte.bit1 = buf_len;
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
    if(flag)
    {
        b.byte.bit2 = 1;
        b.byte.bit1 = count;
        len_res = strlen(result);
        result[len_res++] = b.c;
        result[len_res++] = c;
    }
    else if(buf_len)
    {
        buf[buf_len++] = str[len - 1];
        b.byte.bit2 = 0;
        b.byte.bit1 = buf_len;
        result[len_res++] = b.c;
        strcat(result, buf);
    }
  return result;
}

char * decode(char * str)
{
    int len = strlen(str);
    union bt b;
    int count = 0;
    char * result = (char *)calloc(256, sizeof(char));
    char * temp = calloc(1, sizeof(char));
    for (int i = 0; i < len; i++)
    {
        b.c = str[i];
        if (b.byte.bit2 == 1)
        {
          result = add_nch(b.c - 128, str[i + 1], result);
          i++;
        }
        else
        {
          count = b.byte.bit1;
          while (count)
          {
            i++;
            sprintf(temp, "%c", str[i]);
            strcat(result, temp);
            count--;
          }
        }
    }
    return result;
}
