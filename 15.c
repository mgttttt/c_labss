#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)

int my_atoi(int* n, char* s) {
    int size_s = strlen(s);
    int digit;
    int value = 0;
    for (int i = 0; i < size_s; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
        digit = s[i] - '0';
        value = value * 10 + digit;
    }
    *n = value;
}

void add_nch(int n, char c, char* res)
{
    int len_res = strlen(res);
    while (n)
    {
        res[len_res++] = c;
        n--;
    }
}

int main()
{
    char* str = (char *)calloc(100, sizeof(char));
    char* result = (char*)calloc(100, sizeof(char));
    char* buf = (char*)calloc(10, sizeof(char));
    scanf("%s", str);
    int len = strlen(str), count = 0, flag = 0;
    int len_res = 0;
    int has_digits = 0, number;
    char c;

    for (int i = 0; i < len; i++)
        if (isdigit(str[i]))
        {
            has_digits = 1;
            break;
        }
    if (has_digits)
    {
        for (int i = 0; i < len; i++)
        {
            if (flag)
            {
                if (isdigit(str[i]))
                    count++;
                else
                {
                    *str = *str + i - count;
                    strncpy(buf, str, count);
                    *str = *str - i + count;
                    my_atoi(&number, buf);
                    add_nch(number, str[i], result);
                    len_res += count;
                    result[len_res++] = str[i];
                    count = 0;
                    flag = 0;
                }
            }
            else
            {
                if (isdigit(str[i]))
                {
                    flag = 1;
                    count++;
                }
                else
                    result[len_res++] = str[i];
            }
        }
        printf("%s", result);
    }
    else
    {
        for (int i = 1; i < len; i++)
        {
            if (flag)
            {
                if (str[i] == str[i - 1])
                    count++;
                else
                {
                    sprintf(buf, "%d", count);
                    strcat(result, buf);
                    len_res = strlen(result);
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
                }
                else
                    result[len_res++] = str[i - 1];
            }
        }
        if (flag)
        {
            sprintf(buf, "%d", count);
            strcat(result, buf);
            len_res = strlen(result);
            result[len_res++] = c;
        }
        else result[len_res] = str[len - 1];
        printf("%s\n", result);
    }
    free(result);
    free(str);
    free(buf);
    return 0;
}
