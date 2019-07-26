#include <stdio.h>

#define OUT 0
#define IN  1

int main(int argc, char const *argv[])
{
    int c, wc, state, wlen;
    int testpunctuation, i;
    state = OUT;
    wc = wlen = 0;

    while((c = getchar()) != EOF)
    {
        testpunctuation = (c == ' ' || c == '\t' || c == '\n' || c == '.' || c == ',' || c == '/');
        if(state == OUT && !testpunctuation)
        {
            wlen = 0;
            ++wc;
            state = IN;
            if(wc == 1)
                putchar('\n');
        }
        if(state == IN && !testpunctuation)
        {
            putchar(c);
            ++wlen;
        }
        if(state == IN && testpunctuation)
        {
            state = OUT;
            putchar('\n');
            for(i = 0; i < wlen; ++i)
                putchar('#');
            putchar('\n');
        }
    }

    return 0;
}
