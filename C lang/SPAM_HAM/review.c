#include <stdio.h>
int main()
{
    // operator
    // looping
    /// reading
    // file
    //

    /*char ch = getchar();
    putchar(ch);
    */
    // reading a line
    /*
    char ch;
    while((ch = getchar()) != '\n')
    {
        putchar(ch);
    }
    */
    // printf("%d",EOF);
    char ch;
    int nl = 0;
    int nw = 0;
    int nc = 0;
    /* while((ch = getchar()) != EOF)
    {
        //putchar(ch);
        nc++;
        if(ch == '\n')
            nl++;

        if(ch == ' ' || ch == '\t' || ch == '\n')
        {
            nw++;
        }

    }*/
    int inword = 0;
    while ((ch = getchar()) != EOF)
    {
        // putchar(ch);
        nc++;
        if (ch == '\n')
            nl++;

        if (inword && (ch == ' ' || ch == '\n' || ch == '\t'))
        {
            nw++;
            inword = 0;
        }
        else if (!(ch == ' ' || ch == '\n' || ch == '\t'))
        {
            inword = 1;
        }
    }

    /*
    //solution by student
    int inword = 0;
    while((ch = getchar()) != EOF)
    {
        //putchar(ch);
        nc++;
        if(ch == '\n')
            nl++;

        if((ch == ' ' || ch == '\n' || ch == '\t') && inword)
        {
            nw++;
            inword = 0;
        }
        else
        {
            inword = 1;
        }

    }
    */

    printf("words = %d\nlines = %d\ncharacters=%d\n", nw, nl, nc);
    return 0;
}