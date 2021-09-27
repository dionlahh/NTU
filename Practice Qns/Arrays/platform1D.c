#include <stdio.h>
int platform1D(int ar[], int size);
int main()
{
    int i,b[50],size;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
    scanf("%d",&b[i]);
    printf("platform1D(): %d\n", platform1D(b,size));
    return 0;
}
int platform1D(int ar[], int size)
{
    int count, i, current, max;
    current = ar[0];
    count = 0;
    max = 0;
    for (i=0; i<size; i++)
    {
        if (current == ar[i])
        {
            count++;
        }
        else
        {
            current = ar[i];
            count = 1;
        }

        if (count > max)
        {
            max = count;
        }
    }
    return max;
} 