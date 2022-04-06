#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list list;
typedef struct employee employee;

struct employee{
    int age;
    char surname[100];
    int experience;
    char special[100];
    char gender;
};

struct list {
    struct employee emp;
    list *ptr;
};

list * initialization(employee emp)
{
    list * ls;
    ls = (list *)malloc(sizeof(list));
    ls->emp = emp;
    ls->ptr = NULL;
    return ls;
}

list * add_element(employee emp, list * ls)
{
    list * new_ls;
    new_ls = (list *)malloc(sizeof(list));
    new_ls->ptr = ls->ptr;
    ls->ptr = new_ls;
    new_ls->employee = emp;
    return new_ls;
}

void delete_elem(int n, list * ls)
{
    list * temp;
    int count = 0;
    while (count != n - 1)
    {
        count++;
        ls = ls->ptr;
    }
    temp = ls;
    ls = ls->ptr;
    temp = ls->ptr;
}

int main() {
    employee emp;
    list * ls;

    printf("Enter \"q\" if you want to quit\n");
    printf("Enter \"add\" if you want to add a new element\n");
    printf("Enter \"del\" and then number of element if you want to delete an element\n");
    printf("Enter \"ls\" if you want to see all elements\n");



    return 0;
}
