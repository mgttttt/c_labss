#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int main() {
    struct list* first, *last;
    int q;
    struct employee emp;
    int del;
    first = initialization((employee){20, "name1", 2, "spec2", 'm'});
    last = first;
    last = add_element((employee){25, "name", 2, "spec", 'm'}, last);
    last = add_element((employee){26, "name3", 2, "spec3", 'm'}, last);
    last = add_element((employee){30, "name4", 10, "spec4", 'w'}, last);
    printf("Enter 1 if you want to quit\n");
    printf("Enter 2 if you want to add a new element\n");
    printf("Enter 3 and then number of element if you want to delete element\n");
    printf("Enter 4 if you want to see all elements\n");
    printf("Enter 5 if you want to divide men and women\n");

    while (q != 1)
    {
        printf("-> ");
        scanf("%d", &q);
        if (q == 2)
        {
            emp = emp_add();
            last = add_element(emp, last);
        }
        else if (q == 4)
            all_elements(first);
        else if (q == 3)
        {
            printf("Enter a number of element you want to delete -> ");
            scanf("%d", &del);
            if (del == 1)
                first = delete_first(first);
            else
                delete_elem(del, first);
        }
        else if (q == 5)
            partition(first);
    }
    return 0;
}
