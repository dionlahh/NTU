#include <stdio.h>
void printPattern2(int height);
int main()
{
    int height;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("printPattern2(): \n");
    printPattern2(height);
    return 0;
}
void printPattern2(int height)
{
    int i, j, temp;
    for (i=0; i<height; i++)
    {
        switch(i%2)
        {
            case 0:
                printf("A");
                temp = i/2;
                for (j=0; j<temp; j++)
                {
                    printf("BA");
                }
                printf("\n");
                break;
            
            case 1:
                printf("BA");
                temp = i/2;
                for (j=0; j<temp; j++)
                {
                    printf("BA");
                }
                printf("\n");
                break;
        }
    }
} 