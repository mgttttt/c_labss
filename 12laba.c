#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct films {
    char name[256];
    int year;
    char country[256];
    char producer[256];
    char actors[256];
} films;

void add_note(films c[], int n)
{
    char note[256];
    printf("Enter name -> ");
    fgets(note, 255, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(c[n].name, "%s", note);
    printf("Enter year -> ");
    scanf("%d", &c[n].year);
    fgets(note, 10, stdin);
    printf("Enter country -> ");
    fgets(note, 255, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(c[n].country, "%s", note);
    printf("Enter producer -> ");
    fgets(note, 255, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(c[n].producer, "%s", note);
    printf("Enter actors -> ");
    fgets(note, 255, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(c[n].actors, "%s", note);
}

void all_notes(films c[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d note: name: %s, year: %d, country: %s, producer: %s, actors: %s\n", i + 1, c[i].name, c[i].year, c[i].country, c[i].producer, c[i].actors);
}

void del_note(films c[], int n, int del)
{
    for (int i = del; i < n - 1; i++)
    {
        films temp = c[i];
        c[i] = c[i + 1];
        c[i + 1] = temp;
    }
}

int file_input(FILE* f, films c[])
{
    char str[256];
    char *istr;
    int count = 0;
    while (fgets(str, 256, f) != NULL)
    {
        istr = strtok(str, ";");
        sprintf(c[count].name, "%s", istr);
        istr = strtok(NULL, ";");
        c[count].year = atoi(istr);
        istr = strtok(NULL, ";");
        sprintf(c[count].country, "%s", istr);
        istr = strtok(NULL, ";");
        sprintf(c[count].producer, "%s", istr);
        istr = strtok(NULL, ";");
        sprintf(c[count].actors, "%s", istr);
        count++;
    }
    return count;
}

void file_output(FILE* f, films c[], int count)
{
    for (int i = 0; i < count; i++)
        fprintf(f, "%s;%d;%s;%s;%s\n", c[i].name, c[i].year, c[i].country, c[i].producer, c[i].actors);
}

void find_actor(films c[], char * str, int count)
{
  for (int i = 0; i < count; i++)
    if (!strstr(c[i].actors, str))
        printf("name: %s, year: %d, country: %s, producer: %s, actors: %s\n", c[i].name, c[i].year, c[i].country, c[i].producer, c[i].actors);
}

int main() {
    int count = 0, del;
    char* query = (char*)malloc(sizeof(char) * 100);
    films c[50];
    FILE* file = fopen("input.txt", "r");
    count = file_input(file, c);
    fclose(file);

    printf("Enter \"q\" if you watn to quit\n");
    printf("Enter \"add\" if you want to add a new note\n");
    printf("Enter \"del\" and then number of note if you want to delete a note\n");
    printf("Enter \"ls\" if you want to see all notes\n");
    printf("Enter \"actor\" if you want to see all films with some actor\n");

    while (strcmp(query, "q"))
    {
        printf("-> ");
        fgets(query, 99, stdin);
        query[strlen(query) - 1] = 0;
        if (!strcmp(query, "add"))
        {
            add_note(c, count);
            count++;
        }
        else if (!strcmp(query, "ls"))
            all_notes(c, count);
        else if (!strcmp(query, "del"))
        {
            printf("Enter a number of note you want to delete -> ");
            scanf("%d", &del);
            fgets(query, 10, stdin);
            del_note(c, count, del - 1);
            count--;
        }
        else if (!strcmp(query, "actor"))
        {
          fgets(query, 99, stdin);
          query[strlen(query) - 1] = 0;
          find_actor(c, query, count);
        }
    }
    file = fopen("input.txt", "w");
    file_output(file, c, count);
    fclose(file);
    free(query);
    return 0;
}
