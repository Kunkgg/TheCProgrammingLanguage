#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, wsn;

    wsn = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
            ++wsn;
    }
    printf("\n\nWhite Space Counter: %d\n", wsn);
}
