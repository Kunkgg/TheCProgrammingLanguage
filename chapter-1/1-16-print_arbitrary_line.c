// Exercise 1-16. Revise the main routine of the longest-line program so it
// will correctly print the length of arbitrary long input lines, and as
// much as possible of the text.

// Warning: The problem is that getline() is a standard library function.
// (defined in stdio.h) Your function has the same name and is thus clashing
// with it.

#include <stdio.h>
#define MAXLINE 1000
#define MAXTEXT 1000

int readline(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char const *argv[])
{
    int len, line_num, i;
    char line[MAXLINE];
    char text[MAXTEXT][MAXLINE];
    char tmp[MAXLINE];
    line_num = 0;

    while((len = readline(line, MAXLINE)) > 0)
    {
        copy(text[line_num++], line);
    }
    printf("\n\n==Start to print==\n");
    for ( i = 0; i < line_num; i++)
    {
        printf("%s", text[i]);
    }

    return 0;
}

int readline(char s[], int lim)
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
