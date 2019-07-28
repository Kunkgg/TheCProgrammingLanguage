// Exercise 2-3. Write a function htoi(s), which converts a string of
// hexadecimal digits (including an optional 0x or 0X) into its equivalent
// integer value. The allowable digits are 0 through 9, a through f, and A
// through F.

#include <stdio.h>

#define LINEMAX 1000

int readline(char in_line[]);
int htoi(char line[]);

int main(int argc, char const *argv[])
{
    int len;
    char in_line[LINEMAX];

    while((len = readline(in_line)) > 0) {
        printf("%d\n", htoi(in_line));
    }

    return 0;
}

int readline(char in_line[]){
    int i, c;

    for(i=0; (c=getchar()) != EOF && c != '\n'; ++i){
        in_line[i] = c;
    }
    if(c == '\n')
        in_line[i++] = '\n';
    in_line[i] = '\0';

    return i;
}

int htoi(char line[]) {
    int i;

    if(line[0] == '0' && (line[1] == 'x' || line[1] == 'X')){
        int n = 0;

        for(i=2; line[i] >= '0' && line[i] <= '9' || line[i] >= 'A' && line[i] <= 'F'; ++i){
            if(line[i] >= '0' && line[i] <= '9'){
                n = n * 16 + (line[i] - '0');
            } else
            {
                n = n * 16 + (line[i] - 'A' + 10);
            }
        }

        return n;
    } else
    {
        printf("Input is not a  hexadecimal number.");
        return -1;
    }
}
