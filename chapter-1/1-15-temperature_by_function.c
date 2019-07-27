// Exercise 1.15. Rewrite the temperature conversion program of Section 1.2
// to use a function for conversion.

# include <stdio.h>

float fahr_to_celsius(int fahr);
float celsius_to_fahr(int fahr);
void print_title(char str[]);

int main(int argc, char const *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;
    print_title("The temperature converter(fahr to celsius)");
    while (fahr <= upper)
    {
        celsius = fahr_to_celsius(fahr);
        printf("%12.0f%18.1f\n", fahr, celsius);
        printf("------------------------------------------\n"); 
        fahr = fahr + step;
    }

    print_title("The temperature converter(celsius to fahr)");
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = celsius_to_fahr(celsius);
        printf("%12.0f%18.0f\n", celsius, fahr);
        printf("------------------------------------------\n"); 
        celsius = celsius + step;
    }

    return 0;
}

float fahr_to_celsius(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}

float celsius_to_fahr(int celsius)
{
    return celsius / (5.0 / 9.0) + 32;
}

void print_title(char str[])
{
    printf("==========================================\n"); 
    printf("%s\n", str);
    printf("==========================================\n"); 
}
