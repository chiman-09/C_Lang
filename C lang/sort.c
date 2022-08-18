#include <stdio.h>

void read(int *a, int n);
void disp(int *a, int n);
void sort(int *a, int n);

int main()
{
    int a[100];
    int n;
    printf("enter the number of elements u want to sort\n");
    scanf("%d", &n);
    printf("enter %d elements\n", n);
    read(a, n);
    printf("before sorting\n");
    disp(a, n);
    sort(a, n);
    printf("after sorting\n");
    disp(a, n);
    for (int i = 0; i < 5; i++)
    {
        static int j = 0;
        j = j + i;
        printf("%d", j);
    }
    return 0;
}

void read(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d/n", &a[i]);
    }
}

void disp(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void sort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        for (int j = i; j < n; j++)
        {
            if (a[pos] > a[j])
            {
                pos = j;
            }
        }
        int temp = *(a + i);
        *(a + i) = *(a + pos);
        *(a + pos) = temp;
    }
}
