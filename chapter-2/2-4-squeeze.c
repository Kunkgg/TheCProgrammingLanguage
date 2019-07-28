// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
// each character in s1 that matches any character in the string s2.

#include <stdio.h>

void squeeze(char s[], char d[]);

int main(int argc, char const *argv[])
{
    char test[] = "The Zen of Python, by Tim Peters";
    char d[] = "teo ,";

    squeeze(test, d);

    printf("%s\n", test);
    return 0;
}

void squeeze(char s[], char d[]) {
    int i, j, c, n;
    n = 0;

    for(n=0; d[n] != '\0'; ++n){
        for(i=j=0; s[i] != '\0'; i++)
            if (s[i] != d[n])
                s[j++] = s[i];
        s[j] = '\0';
    }

}
