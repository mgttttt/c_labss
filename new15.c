#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RLE.h"
#include <errno.h>

int main(int argc, char const *argv[])
{
    errno = 0;
    char *str = (char *)calloc(256, sizeof(char));
    char * result = (char *)calloc(256, sizeof(char));
    FILE *fin = fopen(argv[2], "r");
    FILE *fout = fopen(argv[3], "w");
    fgets(str, 256, fin);
    if(!strcmp(argv[1], "e"))
    {
        result = code(str);
        if (errno)
        {
            printf("Memory allocation error!\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        result = decode(str);
        if (errno)
        {
            printf("Memory allocation error!\n");
            exit(EXIT_FAILURE);
        }
    }
    fprintf(fout, "%s", result);
    fclose(fin);
    fclose(fout);
    free(str);
    return 0;
}
