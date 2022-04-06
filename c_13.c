#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:4703)
typedef struct list list;
typedef struct employee employee;

struct employee {
    int age;
    char surname[100];
    int experience;
    char special[100];
    char gender;
};

struct list {
    struct employee emp;
    list* ptr;
};

employee emp_add(void)
{
    employee emp;
    int temp;
    char note[256];
    printf("Enter surname -> ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(emp.surname, "%s", note);
    printf("Enter age -> ");
    scanf("%d", &emp.age);
    fgets(note, 10, stdin);
    printf("Enter specialization -> ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(emp.special, "%s", note);
    printf("Enter experiance -> ");
    scanf("%d", &emp.experience);
    fgets(note, 10, stdin);
    printf("Enter gender -> ");
    scanf("%c", &emp.gender);
    fgets(note, 10, stdin);
    return emp;
}

list* initialization(employee emp)
{
    list* ls;
    ls = (list*)malloc(sizeof(list));
    ls->emp = emp;
    ls->ptr = NULL;
    return ls;
}

list* add_element(employee emp, list* ls)
{
    list* new_ls;
    new_ls = (list*)malloc(sizeof(list));
    new_ls->ptr = ls->ptr;
    ls->ptr = new_ls;
    new_ls->emp = emp;
    return new_ls;
}

void delete_elem(int n, list * ls)
{
    list* temp = ls;
    int count = 0;
    while (count != n - 1)
    {
        count++;
        ls = ls->ptr;
    }
    temp->ptr = ls->ptr;
}

list* delete_first(list* first)
{
    list* new_first = first->ptr;
    return new_first;
}

void all_elements(list* ls)
{
    int count = 0;
    while (ls != NULL)
    {
        count++;
        printf("%d element: surname: %s, age: %d, gender: %c, specialization: %s, experience: %d\n", count, ls->emp.surname, ls->emp.age, ls->emp.gender, ls->emp.special, ls->emp.experience);
        ls = ls->ptr;
    }
}

int main() {
    employee emp;
    list* first, *last;
    char* query = (char*)malloc(sizeof(char) * 100);
    int count_of_el = 0, del;
    printf("Enter \"q\" if you want to quit\n");
    printf("Enter \"add\" if you want to add a new element\n");
    printf("Enter \"del\" and then number of element if you want to delete element\n");
    printf("Enter \"ls\" if you want to see all elements\n");
    
    while (strcmp(query, "q"))
    {
        printf("-> ");
        fgets(query, 100, stdin);
        query[strlen(query) - 1] = 0;
        if (!strcmp(query, "add"))
        {
            emp = emp_add();
            if (!count_of_el)
            {
                first = initialization(emp);
                last = first;
            }
            else last = add_element(emp, last);
            count_of_el++;
        }
        else if (!strcmp(query, "ls"))
            all_elements(first);
        else if (!strcmp(query, "del"))
        {
            printf("Enter a number of element you want to delete -> ");
            scanf("%d", &del);
            fgets(query, 10, stdin);
            if (del == 1) first = delete_first(first);
            else delete_elem(del, first);
            count_of_el--;
        }
    }
    free(query);
    return 0;
}
