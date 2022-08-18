#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main(int argc, char *argv[], char **envp)
{
    /*
    printf("Hello World %d\n", argc);
    for (int i = 0; envp[i] != NULL; i++)
    {
        printf("%s\n", envp[i]);
    }
    char *env = getenv("PATH");
    printf("%s\n", env);
    */
    int sum = 0;
    for (int i = 1; i < argc; i++)
    {
        sum = sum + atoi(argv[i]);
    }
    printf("%d", sum);
    int a = 1;
    int res = a-- == 0 || 2;
    printf("%d %d", a, (res + 1) * *(2));
    return 0;
}