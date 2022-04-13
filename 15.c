#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str    = calloc(100, sizeof(char));
    char *result = calloc(100, sizeof(char));
    char *buf = calloc(10, sizeof(char));
    scanf("%s", str);
    int len = strlen(str), count = 0, flag = 0;
    int len_res = 0;
    char c;

    for(int i = 1; i < len; i++)
    {
        if(flag)
        {
            if(str[i] == str[i - 1])
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
            if(str[i] == str[i - 1])
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
    free(result);
    free(str);
    return 0;
}
