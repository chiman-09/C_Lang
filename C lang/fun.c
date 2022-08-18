#include <stdio.h>
#include <stdlib.h>

typedef struct Employee
{
    char emp_name;
    int emp_id;
    long emp_salary;

} emp_t;

void cat(char *a, char *b);
void disp_empid(emp_t *e, int n);

int main()
{
    char c[100] = "PES";
    char d[20] = "University";
    cat(c, d);
    printf("%s", c);
    int *pt = (int *)malloc(sizeof(int));
    int *pt1 = (int *)calloc(4, sizeof(int));
    printf("%d == ", *pt1);
    return 0;
}

void disp_empid(emp_t *e, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (e[i].emp_salary == 50000)
        {
            printf("%s", e[i].emp_name);
        }
    }
}

void cat(char *a, char *b)
{

    char *ptr1 = a;
    char *ptr2 = b;
    while (*ptr1 != '\0')
    {
        ptr1++;
    }
    while (*ptr2 != '\0')
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *(ptr1 + 1) = '\0';
}