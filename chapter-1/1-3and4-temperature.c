# include <stdio.h>

int main(int argc, char const *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = 0;
    printf("==========================================\n"); 
    printf("The temperature converter(fahr to celsius)\n");
    printf("==========================================\n"); 
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%12.0f%18.1f\n", fahr, celsius);
        printf("------------------------------------------\n"); 
        fahr = fahr + step;
    }

    printf("==========================================\n"); 
    printf("The temperature converter(celsius to fahr)\n");
    printf("==========================================\n"); 
    celsius = 0;
    while (celsius <= upper)
    {
        fahr = celsius / (5.0 / 9.0) + 32;
        printf("%12.0f%18.0f\n", celsius, fahr);
        printf("------------------------------------------\n"); 
        celsius = celsius + step;
    }

    return 0;
}
