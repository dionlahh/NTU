#include <stdio.h>
#include <math.h>
void specialNumbers1D(int ar[], int num, int *size);
int main()
{
    int a[20],i,size=0,num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i=0; i<size; i++)
    printf("%d ",a[i]);
    return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
    int i, j, temp, sum;
    *size = 0;
    for (i=100; i<=num; i++)
    {
        sum = 0;
        j = i;
        do
        {
            temp = j % 10;
            sum += (temp*temp*temp);
            j = j/10;
        } while (j != 0);
        if (sum == i)
        {
            ar[*size] = i;
            (*size)++;
        }
    }
} 