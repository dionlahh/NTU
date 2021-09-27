#include <stdio.h>
#include <math.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n", result);
    return 0;
}
int extEvenDigits1(int num) 
{
    int count = 0, result = 0, temp;
    do
    {
        temp = num % 10;
        if (temp % 2 == 0)
        {
            if(count == 0)
                result += temp;
            else
            {
                result += pow(10, count) * temp;
            }
            count++;
        }
        num = num / 10;
    } while (num != 0);
    return result;
}
void extEvenDigits2(int num, int *result)
{
    int count = 0, temp;
    *result = 0;
    do
    {
        temp = num % 10;
        if (temp % 2 == 0)
        {
            if(count == 0)
                *result += temp;
            else
            {
                *result += pow(10, count) * temp;
            }
            count++;
        }
        num = num / 10;
    } while (num != 0);
}