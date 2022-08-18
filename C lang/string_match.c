#include <stdio.h>
#include <string.h>

/*void match(char *txt, char *pattern)
{
    int txt_length = strlen(txt);
    int pat_length = strlen(pattern);
    int count = 0;
    for (int i = 0; i <= txt_length - pat_length; i++)
    {
        if (txt[i] == pattern[0])
        {
            for (int j = 1; j <= pat_length; j++)
            {
                if (txt[i + j] == pattern[j])
                {
                    count++;
                }
            }
            if (count == pat_length)
            {
                printf("Position of pattern to be found is %d", i);
                count = 0;
            }
        }
    }
}*/
void match(char *txt, char *pattern)
{
    char *p = txt;
    int flag = 0;
    int index = 0;
    while (*p != EOF)
    {
        if (*p == pattern[flag])
        {
            flag++;
            p++;
        }
        if (*p != pattern[flag])
        {
            flag = 0;
            p++;
        }
        if (flag == strlen(pattern))
        {
            index = p - txt - flag;
            printf("%d", index);
        }
    }
}
int main()
{
    char txt[] = "ABCDEF";
    char pat[] = "XF";
    match(txt, pat);
    int a[] = {1, 2, 3, 4, 5};
    printf("%lu", sizeof(a) / sizeof(a[1]));
    return 0;
}