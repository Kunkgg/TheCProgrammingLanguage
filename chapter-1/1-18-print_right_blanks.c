
// Exercise 1-18. Write a program to remove trailing blanks and tabs from
// each line of input, and to delete entirely blank lines.


#include <stdio.h>
#define MAXLINE 1000
#define MAXTEXT 1000
#define LINEWIDTH 80

int readline(char line[], int maxline);
void copy(char to[], char from[]);
char* remove_right_blanks(char line[], int len);

int main(int argc, char const *argv[])
{
    int len, line_num, i;
    char line[MAXLINE];
    char text[MAXTEXT][MAXLINE];
    char tmp[MAXLINE];
    line_num = 0;

    while((len = readline(line, MAXLINE)) > 0)
    {
        copy(text[line_num], remove_right_blanks(line, len));
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

char* remove_right_blanks(char line[], int len)
{
    int i, rc;

    rc = 0;
    if (line[0] == '\n') {
        line[0] = '\0';
        printf("--drop an empty line--");
        return line;
    }
    if (len >=2){
        for(i = len - 2; i >=0 && (line[i] == ' ' || line[i] == '\t'); --i)
        {
            if(line[i-1] == '\n') {
                line[i] = '\0';
            } else
            {
                line[i] = '\n';
                line[i+1] = '\0';
            }
            ++rc;
        }
        printf("--remove %d whitespace from this line--", rc);
    }

    return line;
}
