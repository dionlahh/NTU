#include <stdio.h>

int main()
{
    int mark, ID;

    printf("Enter Student's ID: \n");
    scanf("%d", &ID);

    printf("Enter Mark: \n");
    scanf("%d", &mark);

    switch((mark+5)/10)
    {
        case 10:
        case 9:
        case 8: printf("Grade = A\n"); break;
        case 7: printf("Grade = B\n"); break;
        case 6: printf("Grade = C\n"); break;
        case 5: printf("Grade = D\n"); break;
        default: printf("Grade = F\n"); break; 
    }
    return 0;
}