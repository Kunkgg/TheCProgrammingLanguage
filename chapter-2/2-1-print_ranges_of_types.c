// Exercise 2-1. Write a program to determine the ranges of char, short,
// int, and long variables, both signed and unsigned, by printing
// appropriate values from standard headers and by direct computation.
// Harder if you compute them: determine the ranges of the various
// floating-point types.

// The constants about value ranges are copied from system file
// /usr/include/limits.h


#include <stdio.h>

/* Number of bits in a `char'.	*/
#  define CHAR_BIT	8

/* Minimum and maximum values a `signed char' can hold.  */
#  define SCHAR_MIN	(-128)
#  define SCHAR_MAX	127

/* Maximum value an `unsigned char' can hold.  (Minimum is 0.)  */
#  define UCHAR_MAX	255


/* Minimum and maximum values a `signed short int' can hold.  */
#  define SHRT_MIN	(-32768)
#  define SHRT_MAX	32767

/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */
#  define USHRT_MAX	65535

/* Minimum and maximum values a `signed int' can hold.  */
#  define INT_MIN	(-INT_MAX - 1)
#  define INT_MAX	2147483647

/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */
#  define UINT_MAX	4294967295U

/* Minimum and maximum values a `signed long int' can hold.  */
#  if __WORDSIZE == 64
#   define LONG_MAX	9223372036854775807L
#  else
#   define LONG_MAX	2147483647L
#  endif
#  define LONG_MIN	(-LONG_MAX - 1L)

/* Maximum value an `unsigned long int' can hold.  (Minimum is 0.)  */
#  if __WORDSIZE == 64
#   define ULONG_MAX	18446744073709551615UL
#  else
#   define ULONG_MAX	4294967295UL
#  endif

int power(int base, int n);
long int power_long(int base, int n);
unsigned long power_lu(int base, int n);

int main(int argc, char const *argv[])
{
    char types[10][30] = {
        "signed char",
        "unsigend char",
        "signed short [int]",
        "unsigned short [int]",
        "signed int",
        "unsigned int",
        "signed long [int]",
        "unsigned long [int]",
    };

    printf("%20s\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s\n","Type","Min","Max","Mix-How","Mix-What","Max-How","Max-What");
    printf("%20s\t%20d\t%20d\t%20s\t%20d\t%20s\t%20d\n",types[0],SCHAR_MIN,SCHAR_MAX,"-power(2, 7)",-power(2, 7),"power(2, 8)-1", power(2, 7)-1);
    printf("%20s\t%20d\t%20d\t%20s\t%20d\t%20s\t%20d\n",types[1],0,UCHAR_MAX,"0",0,"power(2, 8)-1", power(2, 8)-1);
    printf("%20s\t%20d\t%20d\t%20s\t%20d\t%20s\t%20d\n",types[2],SHRT_MIN,SHRT_MAX,"-power(2, 15)",-power(2, 15),"power(2, 15)-1", power(2, 15)-1);
    printf("%20s\t%20d\t%20d\t%20s\t%20d\t%20s\t%20d\n",types[3],0,USHRT_MAX,"0",0,"power(2, 16)-1", power(2, 16)-1);
    printf("%20s\t%20d\t%20d\t%20s\t%20d\t%20s\t%20d\n",types[4],INT_MIN,INT_MAX,"-power(2, 31)",-power(2, 31),"power(2, 31)-1", power(2, 31)-1);
    printf("%20s\t%20d\t%20u\t%20s\t%20d\t%20s\t%20u\n",types[5],0,UINT_MAX,"0",0,"power(2, 32)-1", power(2, 32)-1);
    printf("%20s\t%20ld\t%20ld\t%20s\t%20ld\t%20s\t%20ld\n",types[6],LONG_MIN,LONG_MAX,"-power(2, 63)",-power_long(2, 63),"power(2, 63)-1", power_long(2, 63)-1);
    printf("%20s\t%20d\t%20lu\t%20s\t%20d\t%20s\t%20lu\n",types[7],0,ULONG_MAX,"0",0,"power(2, 64)-1", power_lu(2, 64)-1);
    return 0;
}

int power(int base, int n){
    int p;

    for(p=1; n>0; --n)
        p = p * base;
    
    return p;
}

long int power_long(int base, int n){
    long int p;

    for(p=1; n>0; --n)
        p = p * base;
    
    return p;
}

unsigned long power_lu(int base, int n){
    unsigned long p;

    for(p=1; n>0; --n)
        p = p * base;
    
    return p;
}
