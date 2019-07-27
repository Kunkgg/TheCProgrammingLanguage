
// Exercise 1-17. Write a program to print all input lines that are longer
// than 80 characters.


#include <stdio.h>
#define MAXLINE 1000
#define MAXTEXT 1000
#define LINEWIDTH 80

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
        if(len > 80)
            copy(text[line_num++], line);
    }
    if(line_num > 0)
    {
        printf("\n== Start to print (There are %d lines longger than %d)==\n", line_num, LINEWIDTH);
        for ( i = 0; i < line_num; i++)
        {
            printf("%s", text[i]);
        }
    } else
    {
        printf("\n== There isn't a line longger than %d. ==\n", LINEWIDTH);
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
