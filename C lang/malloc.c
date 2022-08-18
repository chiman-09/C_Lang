#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
    int emp_id;
    char name[20];
    char dept[10];
} Emp;

int main()
{
    Emp *s;
    s = (Emp *)calloc(5, sizeof(Emp));
    s = (Emp *)realloc(s, 10 * sizeof(Emp));
    int a[3] = {5, 2, 3};
    int *p = a;
    int *b = p;
    printf("%d", *b);

    free(s);
    FILE *fp = fopen("sample.dat", "r");
    char line[100];
    fgets(line, 100, fp);
    int sum = atoi(strtok(line, " "));
    sum += atoi(strtok(NULL, " "));
    sum += atoi(strtok(NULL, " "));
    sum += atoi(strtok(NULL, " "));
    printf("%d", sum);
    fclose(fp);
    int count = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        count++;
    }
    printf("%d", count);
    return 0;
}
