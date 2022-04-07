#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int main() {
    list* first, *last;
    char* query = (char*)malloc(sizeof(char) * 100);
    employee emp;
    int del;
    first = initialization((employee){20, "name1", 2, "spec2", 'm'});
    last = first;
    last = add_element((employee){25, "name", 2, "spec", 'm'}, last);
    last = add_element((employee){26, "name3", 2, "spec3", 'm'}, last);
    last = add_element((employee){30, "name4", 10, "spec4", 'w'}, last);
    printf("Enter \"q\" if you want to quit\n");
    printf("Enter \"add\" if you want to add a new element\n");
    printf("Enter \"del\" and then number of element if you want to delete element\n");
    printf("Enter \"ls\" if you want to see all elements\n");
    printf("Enter \"divide\" if you want to divide men and women\n");

    while (strcmp(query, "q"))
    {
        printf("-> ");
        fgets(query, 100, stdin);
        query[strlen(query) - 1] = 0;
        if (!strcmp(query, "add"))
        {
            emp = emp_add();
            last = add_element(emp, last);
        }
        else if (!strcmp(query, "ls"))
            all_elements(first);
        else if (!strcmp(query, "del"))
        {
            printf("Enter a number of element you want to delete -> ");
            scanf("%d", &del);
            fgets(query, 10, stdin);
            if (del == 1)
                first = delete_first(first);
            else
                delete_elem(del, first);
        }
        else if (!strcmp(query, "divide"))
            partition(first);
    }
    free(query);
    return 0;
}
