#include <stdio.h>

int main()
{
    int total, count, lines, input;
    double average;
    int i;
    
    printf("Enter number of lines: \n");
    scanf("%d", &lines);
    for (i = 0; i < lines; i++) 
    {
        total=0; count=0;
        printf("Enter line %d (end with -1): \n", i+1);
        scanf("%d", &input);
        while (input != -1)
        {
            total += input;
            count++;  
            scanf("%d", &input);
        }
        average = (double)total/(double)count;
        printf("Average = %.2f\n", average);
    }
   return 0;
}