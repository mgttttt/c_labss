#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cafe {
    char name[256];
    char category[256];
    int calories;
    int grams;
    int price;
} cafe;

void add_note(cafe c[], int n)
{
    char note[256];
    printf("Enter name -> ");
    fgets(note, 255, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(c[n].name, "%s", note);
    printf("Enter category -> ");
    fgets(note, 255, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(c[n].category, "%s", note);
    printf("Enter calories -> ");
    scanf("%d", &c[n].calories);
    printf("Enter grams -> ");
    scanf("%d", &c[n].grams);
    printf("Enter price -> ");
    scanf("%d", &c[n].price);
    fgets(note, 10, stdin);
}

void all_notes(cafe c[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d note: name: %s, category: %s, calories: %d, grams: %d, price: %d\n", i + 1, c[i].name, c[i].category, c[i].calories, c[i].grams, c[i].price);
}

void del_note(cafe c[], int n, int del)
{
    for (int i = del; i < n - 1; i++)
    {
        cafe temp = c[i];
        c[i] = c[i + 1];
        c[i + 1] = temp;
    }
}

int file_input(FILE* f, cafe c[])
{
    char str[256];
    char *istr;
    int count = 0;
    while (fgets(str, 256, f) != NULL)
    {
        istr = strtok(str, ";\n");
        sprintf(c[count].name, "%s", istr);
        istr = strtok(NULL, ";\n");
        sprintf(c[count].category, "%s", istr);
        istr = strtok(NULL, ";\n");
        c[count].calories = atoi(istr);
        istr = strtok(NULL, ";\n");
        c[count].grams = atoi(istr);
        istr = strtok(NULL, ";\n");
        c[count].price = atoi(istr);
        count++;
    }
    return count;
}

void file_output(FILE* f, cafe c[], int count)
{
    for (int i = 0; i < count; i++)
        fprintf(f, "%s;%s;%d;%d;%d\n", c[i].name, c[i].category, c[i].calories, c[i].grams, c[i].price);
}

void find_second_course(cafe c[], int count)
{
  for (int i = 0; i < count; i++)
    if (!strcmp(c[i].category, "second course"))
        printf("name: %s, category: %s, calories: %d, grams: %d, price: %d\n", c[i].name, c[i].category, c[i].calories, c[i].grams, c[i].price);
}

int main() {
    int count = 0, del;
    char* query = (char*)malloc(sizeof(char) * 100);
    cafe c[50];
    FILE* file = fopen("input.txt", "r");
    count = file_input(file, c);
    fclose(file);

    printf("Enter \"q\" if you watn to quit\n");
    printf("Enter \"add\" if you want to add a new note\n");
    printf("Enter \"del\" and then number of note if you want to delete a note\n");
    printf("Enter \"ls\" if you want to see all notes\n");
    printf("Enter \"second\" if you want to see all second courses\n");

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
        else if (!strcmp(query, "second"))
          find_second_course(c, count);
    }
    file = fopen("input.txt", "w");
    file_output(file, c, count);
    fclose(file);
    free(query);
    return 0;
}
