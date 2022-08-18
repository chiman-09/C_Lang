#include <stdio.h>
int main()
{
    volatile int a = 0;
    if (a == 0)
        printf("a is 0\n");
    else
        printf("a is not zero\n");
    return 0;
}