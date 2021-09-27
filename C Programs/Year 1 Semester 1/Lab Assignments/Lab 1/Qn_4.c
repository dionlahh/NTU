#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double x, numerator, denominator = 1.0, sum = 1.0;
    printf("Enter x: \n");
    scanf("%lf", &x);

    for (i=1; i<=10; i++)
    {
        denominator = denominator * i;
        numerator =  pow(x, i);
        sum += (numerator / denominator);
    }
    printf("Result = %.2lf", sum);

    return 0;
}