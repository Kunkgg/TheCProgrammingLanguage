#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("[#][#][#]\n");
    printf("[-][-][-]\n");
    printf("[][][]\n");
    printf("###\n");
    printf("#") * 5;
    printf("\n");
    printf("\c");  // This line will be warned while compiling
    printf("\n");
}
