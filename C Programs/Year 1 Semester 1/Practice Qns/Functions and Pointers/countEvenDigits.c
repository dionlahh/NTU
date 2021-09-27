#include <stdio.h>
int countEvenDigits1(int number);
void countEvenDigits2(int number, int *count);
int main()
{
    int number, result;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("countEvenDigits1(): %d\n", countEvenDigits1(number));
    countEvenDigits2(number, &result);
    printf("countEvenDigits2(): %d\n", result);
    return 0;
}
int countEvenDigits1(int number)
{
    int i, count = 0;
    do
    {
        if(number % 2 == 0)
            count++;
        number = number / 10;
    } while (number != 0);
    return count;
}
    
void countEvenDigits2(int number, int *count)
{
    int i;
    *count = 0;
    do
    {
        if(number % 2 == 0)
            (*count)++;
        number = number / 10;
    } while (number != 0);
} 