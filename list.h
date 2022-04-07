#ifndef LIST_H
#define LIST_H
typedef struct list list;
typedef struct employee employee;

struct employee {
    int age;
    char surname[256];
    int experience;
    char special[256];
    char gender;
};

struct list {
    struct employee emp;
    list* ptr;
};


employee emp_add(void)
{
    employee emp;
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
    printf("Enter experience -> ");
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

void partition(list * ls)
{
    list * m, * w, *temp_m, *temp_w;
    int count_m = 0, count_w = 0;
    while (ls != NULL)
    {
        if (ls->emp.gender == 'm')
        {
            count_m++;
            if (count_m == 1)
            {
                m = initialization(ls->emp);
                temp_m = m;
            }
            else temp_m = add_element(ls->emp, temp_m);
        }
        else
        {
            count_w++;
            if (count_w == 1)
            {
                w = initialization(ls->emp);
                temp_w = w;
            }
            else temp_w = add_element(ls->emp, temp_w);
        }
        ls = ls->ptr;
    }
    printf("men\n");
    all_elements(m);
    printf("women\n");
    all_elements(w);
}
#endif /*LIST_H*/
