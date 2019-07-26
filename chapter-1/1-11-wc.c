#include <stdio.h>

#define OUT 0
#define IN  1

int main(int argc, char const *argv[])
{
    int c, nc, nl, nw, state;
    nc = nl = nw = 0;
    state = OUT;
    while((c = getchar()) != EOF)
    {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        } 
    }
    printf("\n\nnc: %d, nl: %d, nw: %d\n", nc, nl, nw);
    return 0;
}
