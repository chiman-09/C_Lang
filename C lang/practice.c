#include <stdio.h>
void f1(int x);
void f2(int *q);
void f3(int *q);
int main()
{

    /*int x = 100;
    printf("x using x is %d \n", x);
    //f1(x);
    printf("x using x is %c \n", x);

    int *p;
    p = &x;
    printf("x using x is %d and using p is %d \n", x, *p);
    f2(p);
    printf("x using x is %d and using p is %d \n", x, *p);

    printf("x using x is %d and using p is %d \n", x, *p);
    f3(p);
    printf("x using x is %d and using p is %d \n", x, *p);*/

    // int term = 1, i, n;
    // printf("%d", i);

    int _PES = 10;
    int _1_2_PES = 19;
    int a = 2;
    int b = 4;
    printf("%f", (float)a / (float)b);
    a = a << 2;
    printf("\n%d", a);
    a = ~a;
    printf("\n%d", a);
    int c = 10;
    if (c++ == 10 || c++ == 11)
    {
        printf("\n%d", c);
    }
    return 0;
}

void f1(int x)
{
    x = 200;
}

void f2(int *q)
{
    int temp = 200;
    q = &temp;
}

void f3(int *q)
{
    int temp = 200;
    *q = temp;
}