#include <stdio.h>
#include <string.h>
#define N 20
char *longestStrInAr(char str[N][40], int size, int *length);
int main()
{
    int i, size, length;
    char str[N][40], first[40], last[40], *p, *result;
    char dummychar;

    printf("Enter array size: \n");
    scanf("%d", &size);
    scanf("%c", &dummychar);
    for (i=0; i<size; i++) 
    {
        printf("Enter string %d: \n", i+1);
        fgets(str[i], 40, stdin);
        if (p=strchr(str[i],'\n')) *p = '\0';
    }
    result = longestStrInAr(str, size, &length);
    printf("longest: %s \nlength: %d\n", result, length);
    return 0;
}
char *longestStrInAr(char str[N][40], int size, int *length)
{
    int store[size];
    int count, i, j, max_pos;
    
    for (i=0; i<size; i++)
    {
        store[i] = 0;
        j = 0;
        do
        {
            store[i]++;
            j++;
        } while (str[i][j] != '\0');
    }

    *length = store[0];
    max_pos = 0;
    for (i=0; i<size; i++)
    {
        if (store[i] > *length)
        {
            *length = store[i];
            max_pos = i;
        }
    }
    return str[max_pos];
} 