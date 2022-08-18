#include <stdio.h>

struct test
{
    int i;
    float j;
};

void read(struct test *d)
{
    printf("Enter value of i\n");
    scanf("%d\n", &(d->i));
    fflush(stdin);
    printf("Enter value of j\n");
    scanf("%f\n", &(d->j));
};

int main()
{

    struct test t;
    read(&t);
    printf("%d", t.i);
    return 0;
}