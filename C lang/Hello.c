#include <stdio.h>
int main()
{
    int width;
    printf("Enter width of diamond: ");
    scanf("%d", &width);
    int i = 0;
    for (; i < width; i++)
    {
        for (int j = 0; j <= (2 * width); j++)
        {
            if (j == (((2 * width) - 1) / 2 - i) || j == (((2 * width) - 1) / 2 + i))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    i = i - 2;
    for (; i >= 0; i--)
    {
        for (int j = 0; j <= (2 * width); j++)
        {
            if (j == (((2 * width) - 1) / 2 - i) || j == (((2 * width) - 1) / 2 + i))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}