#include <stdio.h>

#define OUT 0
#define IN  1

int main(int argc, char const *argv[])
{
    int c, wc, state, wlen;
    int testwhite, i;
    state = OUT;
    wc = wlen = 0;

    while((c = getchar()) != EOF)
    {
        testwhite = (c == ' ' || c == '\t' || c == '\n');
        if(state == OUT && !testwhite)
        {
            wlen = 0;
            ++wc;
            state = IN;
            if(wc == 1)
                putchar('\n');
        }
        if(state == IN && !testwhite)
        {
            putchar(c);
            ++wlen;
        }
        if(state == IN && testwhite)
        {
            state = OUT;
            printf("%c\n", c);
            for(i = 0; i < wlen; ++i)
                printf("#");
            printf("\n");
        }
    }

    return 0;
}
