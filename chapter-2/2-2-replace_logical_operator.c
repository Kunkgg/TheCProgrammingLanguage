// Exercise 2-2. Write a loop equivalent to the for loop above without using
// && or ||.

// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//     s[i] = c;

#include <stdio.h>

#define MAXLINE 1000

int main(int argc, char const *argv[])
{
    int i, c, lim;

    char line[MAXLINE];
    lim = MAXLINE;

    for (i=0; (i< lim-1)*((c=getchar()) - '\n')*(c-EOF); ++i)
        line[i] = c;
    line[i] = '\n';
    line[++i] = '\0';

    printf("%s\n", line);

    return 0;
}
