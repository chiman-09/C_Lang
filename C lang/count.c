#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
int main()
{
    int nc = 0;
    char ch;
    int nl = 0;
    int nw = 0;
    int inword = 1;
    while ((ch = getchar()) != EOF)
    {
        // putchar(ch);
        nc++;
        if (ch == '\n')
            nl++;

        if ((ch == ' ' || ch == '\n' || ch == '\t') && inword)
        {
            nw++;
            inword = 0;
        }
        else
        {
            inword = 1;
        }
    }

    printf("words = %d\nlines = %d\ncharacters=%d\n", nw, nl, nc);
    return 0;
}
----------
void fun1(int a);
int main()
{
    int a1 = 100;
    printf("before function call a1 is %d\n", a1); // a1 is 100
    fun1(a1);                                      // call
    printf("after function call a1 is %d\n", a1);  // a1 is 100
    return 0;
}
void fun1(int a1)
{
    printf("a1 in fun1 before changing %d\n", a1); // 100
    a1 = 200;
    printf("a1 in fun1 after changing %d\n", a1); // 200
}

--------

void fun1(int *a1);
int main()
{
    int a1 = 100;
    printf("before function call a1 is %d\n", a1); // 100
    fun1(&a1);                                     // call
    printf("after function call a1 is %d\n", a1);  // 100
}
void fun1(int *a1)
{
    int b = 200;
    printf("*a1 in fun1 before changing %d\n", *a1); // 100
    a1 = &b;
    printf("*a1 in fun1 after changing %d\n", *a1); // 200
}
*/

void fun1(int *a1);
int main()
{
    int a1 = 100;
    printf("before function call a1 is %d\n", a1); // 100
    fun1(&a1);                                     // call
    printf("after function call a1 is %d\n", a1);  // 200
    printf("%lu", strlen("\n"));
    /*
        char s1[] = "PES";
        char s2[4];
        s2 = s1; // error: array type 'char [4]' is not assignable
        s2[0] = 'M';
        printf("%s", s1);
        */
    int *p_int = (int *)malloc() int a[10] = {[3] = 5, [7] = 4};
    printf("%d", a[0]);
    int *ptr = a;
    printf("%p  %p", &a, ptr);
    printf("%d", 21 / 2);
    int num;
    scanf("\n%d", &num);
    int bin = 0;
    int count = 1;
    while (num > 0)
    {
        bin += (num % 2) * count;
        count *= 10;
        num /= 2;
    }
    printf("%d", bin);
    return 0;
}
void fun1(int *a1)
{
    printf("*a1 in fun1 before changing %d\n", *a1); // 100
    *a1 = 200;
    printf("*a1 in fun1 after changing %d\n", *a1); // 200
}