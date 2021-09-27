#include <stdio.h>
void computeTotal(int numOfLines);
int main()
{
    int numOfLines;
    printf("Enter number of lines: \n");
    scanf("%d", &numOfLines); 
    computeTotal(numOfLines);
    return 0;
}
void computeTotal(int numOfLines)
{
    int i, x, j, temp, sum;
    for (i=0; i<numOfLines; i++)
    {
        sum = 0;
        printf("Enter line %d: \n", i+1);
        scanf("%d", &x);
        for (j=0; j<x; j++)
        {
            scanf("%d", &temp);
            sum += temp;
        }
        printf("Total: %d\n", sum);
    }
} 