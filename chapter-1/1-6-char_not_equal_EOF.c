// Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 1;

    // ctrl-c stop loop only
    while (i)
    {
        // ctrl-d is EOF, EOF only can be first char of a line
        printf("getchar() != EOF : %d\n", (getchar() != EOF));
    }
    
    return 0;
}
