#include <stdio.h>
#include <string.h>
struct
{
    unsigned int age : 3;
} Age;

enum month
{
    Jan,
    Feb,
    Mar
};
int main()
{
    /*
    Age.age = 4;
    printf("Sizeof( Age ) : %d\n", sizeof(Age));
    printf("Age.age : %d\n", Age.age);
    Age.age = 10;
    printf("Sizeof( Age ) : %d\n", sizeof(Age));
    printf("Age.age : %d\n", Age.age);
    ---------------------------------
    int h, t, u;
    int num;
    for (int i = 0; i < 1000; i++)
    {
        num = i;
        u = i % 10;
        i /= 10;
        t = i % 10;
        i /= 10;
        h = i % 10;
        int cube = (h * h * h) + (t * t * t) + (u * u * u);
        if (cube == num)
        {
            printf("%d\n", num);
        }
        i = num;
    }
------------------------------------------
    FILE *fp = fopen("data.txt", "r");
    int nl = 0;
    int nw = 0;
    if (fp == NULL)
    {
        printf("file does not exist");
    }
    else
    {

        while (fgetc(fp) != EOF)
        {
            char ch = fgetc;
            printf("%c", ch);
            if (ch == '\n')
            {
                nl++;
                printf("%c", ch);
            }
        }
    }
    fclose(fp);
    printf("%d", nl);
    */
    // FILE *pdata = fopen("data.txt", "r+");
    //  for (int i = 65; i < 90; i++)
    //  {
    //      fputc(i, pdata);
    //  }
    /*
        for (int i = 65; i < 90; i++)
        {
            char c = fgetc(pdata);
            printf("%c", c);
        }

    char s[100] = "I am the gratest mjhdkhad alive";
    fputs(s, pdata);
    fputs(s, pdata);
    fgets(s, 25, pdata);
    puts(s);
    fclose(pdata);
    */
    FILE *fp = fopen("data.txt", "r");
    char s[100];
    fgets(s, 25, fp);
    fgets(s, 25, fp);
    puts(s);

    fclose(fp);
    return 0;
}