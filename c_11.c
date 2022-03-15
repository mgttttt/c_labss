#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

struct market {
    char* name = (char*)malloc(sizeof(char) * 100);
    char* brand = (char*)malloc(sizeof(char) * 100);
    char* model = (char*)malloc(sizeof(char) * 100);
    int price;
};

void add_note(market spare_parts[], int n)
{
    int price;
    char* note = (char *)malloc(sizeof(char) * 100);
    printf("Enter name -> ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(spare_parts[n].name, "%s", note);
    printf("Enter brand -> ");
    fgets(note, 100, stdin); 
    note[strlen(note) - 1] = 0;
    sprintf(spare_parts[n].brand, "%s", note);
    printf("Enter model -> ");
    fgets(note, 100, stdin); 
    note[strlen(note) - 1] = 0;
    sprintf(spare_parts[n].model, "%s", note);
    printf("Enter price -> ");
    scanf("%d", &price);
    fgets(note, 10, stdin);
    spare_parts[n].price = price;
}

void all_notes(market spare_parts[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d note: name: %s, brand: %s, model: %s, price: %d\n", i + 1, spare_parts[i].name, spare_parts[i].brand, spare_parts[i].model, spare_parts[i].price);
}

void del_note(market spare_parts[], int n, int del)
{
    for (int i = del; i < n - 1; i++)
    {
        market temp = spare_parts[i];
        spare_parts[i] = spare_parts[i + 1];
        spare_parts[i + 1] = temp;
    }
}

int main() {
    int count = 0;
    int del;
    char* query = (char*)malloc(sizeof(char) * 100);
    struct market spare_parts[20];

    printf("Enter \"q\" if you watn to quit\n");
    printf("Enter \"add\" if you want to add a new note\n");
    printf("Enter \"del (number note)\" if you want to delete a note\n");
    printf("Enter \"ls\" if you want to see all notes\n");

    while (strcmp(query, "q"))
    {
        printf("-> ");
        fgets(query, 100, stdin);
        query[strlen(query) - 1] = 0;
        if (!strcmp(query, "add"))
        {
            add_note(spare_parts, count);
            count++;
        }
        else if (!strcmp(query, "ls"))
            all_notes(spare_parts, count);
        else if (!strncmp(query, "del ", 4))
        {
            scanf("%d", &del);
            del_note(spare_parts, count, del - 1);
            count--;
        }
    }

    return 0;
}
