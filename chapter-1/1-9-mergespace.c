#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, last;
    while((c = getchar()) != EOF)
    {
        if(c != ' ')
        {
            putchar(c);
            last = c;
        }
        else if (last != ' ')
        {
            putchar(c);
            last = c;
        }
    }
    return 0;
}
