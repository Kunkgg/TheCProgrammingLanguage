
// Exercise 1-19. Write a function reverse(s) that reverses the character
// string s. Use it to write a program that reverses its input a line at a
// time.

#include <stdio.h>
#define MAXLINE 1000
#define MAXTEXT 1000
#define LINEWIDTH 80

int readline(char line[], int maxline);
void copy(char to[], char from[]);
char* reverse(char line[], int len);

int main(int argc, char const *argv[])
{
    int len, line_num, i;
    char line[MAXLINE];
    char text[MAXTEXT][MAXLINE];
    char tmp[MAXLINE];
    line_num = 0;

    while((len = readline(line, MAXLINE)) > 0)
    {
        copy(text[line_num], reverse(line, len));
        ++line_num;
    }
    if(line_num > 0)
    {
        printf("\n== Start to print ==\n");
        for ( i = 0; i < line_num; i++)
        {
            printf("%s", text[i]);
        }
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

char* reverse(char line[], int len)
{
    int i, t;

    for(i = len-1; i >= len / 2; --i)
    {
        t = line[i];
        line[i] = line[len-2-i];
        line[len-2-i] = t;
    }

    return line;
}
