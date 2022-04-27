#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void add_nch(int n, char c, FILE * fout)
{
    while (n)
    {
        fprintf(fout, "%c", c);
        n--;
    }
}

int main(int argc, char const *argv[])
{
    char *str = (char *)calloc(256, sizeof(char));
    char *result = (char *)calloc(256, sizeof(char));
    char *buf = (char *)calloc(256, sizeof(char));
    FILE *fin = fopen(argv[2], "r");
    FILE *fout = fopen(argv[3], "w");
    fgets(str, 256, fin);
    union bt b;
    int len = strlen(str), count = 0, flag = 0;
    int len_res = 0, buf_len = 0;
    char c;
    if(!strcmp(argv[1], "e"))
    {
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
      fprintf(fout, "%s", result);
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            b.c = str[i];
            if (b.byte.bit2 == 1)
            {
              add_nch(b.c - 128, str[i + 1], fout);
              i++;
            }
            else
            {
              count = b.byte.bit1;
              while (count)
              {
                i++;
                fprintf(fout, "%c", str[i]);
                count--;
              }
            }
        }
    }
    fclose(fin);
    fclose(fout);
    free(result);
    free(str);
    free(buf);
    return 0;
}

