#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str)
{
    int i, len, j, pos;
    char temp;
    len = strlen(str);

    temp = str[0];
    pos = 0;
    for (i=0; i<len; i++)
    {
        if (str[i] > temp)
        {
            temp = str[i];
            pos = i;
        }
    }

    for (i=pos; i>0; i--)
    {
        str[i] = str[i-1];
    }
    str[0] = temp;
} 