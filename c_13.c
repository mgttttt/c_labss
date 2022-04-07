#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int main() {
    list* first, *last;
    char* query = (char*)malloc(sizeof(char) * 100);
    int count_of_el = 0, del;
    employee emp = {
      .age = 20,
      .surname = "name1",
      .experience = 2,
      .special = "spec1",
      .gender = 'm'};
    first = initialization(emp);
    last = first;
    count_of_el++;
    employee emp2 = {
      .age = 25,
      .surname = "name2",
      .experience = 5,
      .special = "spec2",
      .gender = 'w'};
    last = add_element(emp2, last);
    employee emp3 = {
      .age = 26,
      .surname = "name3",
      .experience = 2,
      .special = "spec3",
      .gender = 'm'};
    last = add_element(emp3, last);
    employee emp4 = {
      .age = 30,
      .surname = "name4",
      .experience = 10,
      .special = "spec4",
      .gender = 'w'};
    last = add_element(emp4, last);
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
            count_of_el++;
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
            count_of_el--;
        }
        else if (!strcmp(query, "divide"))
            partition(first);
    }
    free(query);
    return 0;
}
