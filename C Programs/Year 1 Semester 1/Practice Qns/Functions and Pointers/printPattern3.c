#include <stdio.h>
void printPattern3(int height);
int main()
{
    int height;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("printPattern3(): \n");
    printPattern3(height);
    return 0;
}
void printPattern3(int height)
{
    int i, j, next;
    for (i=0; i<height; i++)
    {
        next = i+1;
        if (next == 10)
        {
            next = 0;
        }
        printf("%d", next);
        for (j=0; j<i; j++)
        {
            next++;
            if (next == 10)
            {
            next = 0;
            }
            printf("%d", next);
        }
        printf("\n");
    }

} 