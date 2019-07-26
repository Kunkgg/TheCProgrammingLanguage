#include <stdio.h>

#define RANGE   '~'-'!'+1
#define LOWER   '!'
#define PLOTSYM '#'

void plotHorizontal(void);
void plotVertical(void);


int main(int argc, char const *argv[])
{
    plotHorizontal();
    plotVertical();
}

void plotHorizontal(void)
{
    int c, i, j;
    int charc[RANGE];

    for(i = 0; i < RANGE; ++i)
        charc[i] = 0;

    while((c = getchar()) != EOF)
    {
        if(c >= '!' && c <= '~')
            ++charc[c-LOWER];
    }
    putchar('\n');
    for(i = 0; i < RANGE; ++i)
    {
        if(charc[i] > 0)
        {
            putchar(i + LOWER);
            putchar(' ');
            for(j = 0; j < charc[i]; ++j)
                putchar(PLOTSYM);
            putchar('\n');
        }
    }
}

void plotVertical(void)
{

}
