#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)
int is_pallindrom(char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - 1 - i]) return 0;
    return len;
}

int main() {
    int temp; int max_sz = 0;
    char* result = (char *)malloc(sizeof(char) * 100);
    char* str = (char *)malloc(sizeof(char) * 100);
    printf("%s", "Enter string: ");
    fgets(str, 100, stdin);
    char delim[] = ", \n";
    char* p = strtok(str, delim);
    temp = is_pallindrom(p);
    if (temp && temp > max_sz)
    {
        max_sz = temp;
        result = p;
    }
    while ((p = strtok(NULL, delim)) != NULL)
    {
        temp = is_pallindrom(p);
        if (temp && temp > strlen(result))
            result = p;
    }
    if (max_sz == 0) printf("There are no pallindroms\n");
    else
        printf("%s\n", result);
    return 0;
}
