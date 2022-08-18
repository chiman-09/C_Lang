#include <stdio.h>
#include <math.h>
// user defined data type
// using structure we can define a data type which holds more than one element of different types
// structure was used as array can store only homogenous datatypes
struct Employee // this whole line is a data type -- so no memory allocated
{
    int number;
    char name[20];
    float salary;
};
struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

int main()
{
    /*    //struct Employee e; // e is an internal pointer variable
    //printf("Size of Emp: %lu\n", sizeof(e));
    //printf("Size of Emp: %lu", sizeof(struct Employee));
    struct Employee e = {1001, "Karthik", 50000};
    printf("%d %s %f", e.number, e.name, e.salary);
    int a = sqrt(4) * 2;
    printf("%d", a); */

    struct point makepoint(int x, int y)
    {
        struct point temp;
        temp.x = x;
        temp.y = y;
        return temp;
    }
    return 0;
}