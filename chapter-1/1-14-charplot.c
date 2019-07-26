#include <stdio.h>

#define RANGE   '~'-'!'+1
#define LOWER   '!'
#define PLOTSYM '#'

void plotHorizontal(int *);
void plotVertical(int *);
int * charCounter(void);
int max(int *);

int charc[RANGE];

int main(int argc, char const *argv[])
{
    int * charc;

    charc = charCounter();
    printf("==========================================\n"); 
    printf("The Horizontal Plot\n");
    printf("==========================================\n"); 
    plotHorizontal(charc);
    printf("==========================================\n"); 
    printf("The Vertical Plot\n");
    printf("==========================================\n"); 
    plotVertical(charc);
}

int* charCounter(void)
{
    int c, i, j;

    for(i = 0; i < RANGE; ++i)
        charc[i] = 0;

    while((c = getchar()) != EOF)
    {
        if(c >= '!' && c <= '~')
            ++charc[c-LOWER];
    }

    return charc;
}

void plotHorizontal(int *charc)
{
    int i, j;

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

int max(int *arr)
{
    int i, m;
    m = 0;

    for(i = 0; i < RANGE; ++i)
    {
        if(arr[i] > m)
            m = arr[i];
    }

    return m;
}

void plotVertical(int *charc)
{
    int maxHeight, i, j, row;
    int charcCopy[RANGE];
    maxHeight = max(charc);

    int rows[maxHeight][RANGE];

    // make a copy of charc list
    for (i = 0; i < RANGE; i++)
    {
        charcCopy[i] = charc[i];
    }

    // store charcounter list in a 2d array
    for (i = 0; i < maxHeight; i++)
    {
        for (j = 0; j < RANGE; j++)
        {
            if(charc[j] > 0)
            {
                rows[i][j] = 1;
                charc[j] = charc[j] - 1;
            }
            else
            {
                rows[i][j] = 0;
            }
        }
    }

    // print the vertical plot, drop the empty colnums
    for(row = maxHeight - 1; row >= 0; row--)
    {
        int i;

        for (i = 0; i < RANGE; i++)
        {
            if(charcCopy[i] > 0){
                if(rows[row][i] > 0)
                {
                    putchar(PLOTSYM);
                    putchar(' ');
                }
                else
                {
                    putchar(' ');
                    putchar(' ');
                }
            }
        }
        putchar('\n');
    }

    // print the chars as x-axis
    for (i = 0; i < RANGE; i++)
    {
        if(charcCopy[i] > 0)
        {
            putchar(i + LOWER);
            putchar(' ');
        }
    }
    putchar('\n');
}
