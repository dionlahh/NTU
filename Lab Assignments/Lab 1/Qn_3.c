#include <stdio.h>

int main()
{
    int height, i, j;
    printf("Enter the height:\n");
    scanf("%d", &height);

    for (i=1; i<=height; i++)
    {
        switch(i%3)
        {
            case 1:
            for (j=0; j<i; j++)
            {
                printf("1");
            }
            printf("\n");
            break;

            case 2:
            for (j=0; j<i; j++)
            {
                printf("2");
            }
            printf("\n");
            break;

            case 0:
            for (j=0; j<i; j++)
            {
                printf("3");
            }
            printf("\n");
            break;
            
        }
    }

    return 0;
}

/* Suggested Answer:
#include <stdio.h>
int main()
{
   int row, col, height;
   int num = 0;
   printf("Enter the height: \n");
   scanf("%d", &height);
   printf("Pattern: \n");
   for (row = 0; row < height; row++)  
   {
      for (col = 0; col < row+1; col++)      // print numbers
         printf("%d",num+1);
      num = (num + 1) % 3;             // print up to number 3
      printf("\n");
   }
   return 0;
}
*/