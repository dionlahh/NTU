#include <stdio.h>
int perfectProd1(int num);
void perfectProd2(int num, int *prod);
int main()
{
 int number, result=1;

 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("Calling perfectProd1() \n");
 printf("perfectProd1(): %d\n", perfectProd1(number));

 printf("Calling perfectProd2() \n");
 perfectProd2(number, &result);
 printf("perfectProd2(): %d\n", result);
 return 0;
}
int perfectProd1(int num)
{
    int numBefore, i, sum, product = 1, perf1 = 0, perf2 = 0;
    for (numBefore = 1; numBefore<num; numBefore++)
    {
        sum = 0;
        for (i = 1; i<numBefore; i++)
        {
            if (numBefore % i == 0)
            {
                sum += i;
            }
        }
        if (sum == numBefore)
        {
            printf("Perfect number: %d\n", sum);
            perf1 = sum;
            product = perf1 * perf2;
            if (product == 0)
                perf2 = perf1;
            else perf2 = product;

        }
    }
    return product;
}
void perfectProd2(int num, int *prod)
{
    int numBefore, i, sum, product = 1, perf1 = 0, perf2 = 0;
    for (numBefore = 1; numBefore<num; numBefore++)
    {
        sum = 0;
        for (i = 1; i<numBefore; i++)
        {
            if (numBefore % i == 0)
            {
                sum += i;
            }
        }
        if (sum == numBefore)
        {
            printf("Perfect number: %d\n", sum);
            perf1 = sum;
            (*prod) = perf1 * perf2;
            if ((*prod) == 0)
                perf2 = perf1;
            else perf2 = (*prod);
        }
    }
}
