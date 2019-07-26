#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    // printf("EOF value is: %d\n", EOF);
    // printf("%d\n", getchar() != EOF);

    return 0;

}
