#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    while((c = getchar()) != EOF)
    {
        if(c == '\t')
            printf("\\t");
        else if (c == 8 || c == 127)
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
    return 0;
}
