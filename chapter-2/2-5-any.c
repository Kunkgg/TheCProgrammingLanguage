// Exercise 2-5. Write the function any(s1,s2), which returns the first
// location in a string s1 where any character from the string s2 occurs, or
// -1 if s1 contains no characters from s2. (The standard library function
// strpbrk does the same job but returns a pointer to the location.)

# include <stdio.h>

int any(char s[], char d[]);

int main(int argc, char const *argv[])
{
    char s[] = "The Zen of Python, by Tim Peters";
    char d[] = "teo ,";

    printf("str1: %s\n",s);
    printf("str2: %s\n",d);
    printf("res:  %d\n", any(s, d));
    return 0;
}

int any(char s[], char d[]) {
    int i, n;
    n = 0;

    for(n=0; s[n] != '\0'; ++n){
        for(i=0; d[i] != '\0'; i++)
            if (s[n] == d[i])
                return n;
    }

    return -1;
}
