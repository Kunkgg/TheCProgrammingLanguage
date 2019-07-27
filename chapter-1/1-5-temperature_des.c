// Exercise 1-5. Modify the temperature conversion program to print the
// table in reverse order, that is, from 300 degrees to 0.

# include <stdio.h>

int main(int argc, char const *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = upper;
    printf("==========================================\n"); 
    printf("The temperature converter(fahr to celsius)\n");
    printf("==========================================\n"); 
    while (fahr >= lower)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%12.0f%18.1f\n", fahr, celsius);
        printf("------------------------------------------\n"); 
        fahr = fahr - step;
    }

    printf("==========================================\n"); 
    printf("The temperature converter(celsius to fahr)\n");
    printf("==========================================\n"); 
    celsius = upper;
    while (celsius >= lower)
    {
        fahr = celsius / (5.0 / 9.0) + 32;
        printf("%12.0f%18.0f\n", celsius, fahr);
        printf("------------------------------------------\n"); 
        celsius = celsius - step;
    }

    return 0;
}
