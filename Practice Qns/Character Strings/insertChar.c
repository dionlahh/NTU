#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80],b[80];
    char ch, *p;

    printf("Enter a string: \n");
    fgets(a, 80, stdin);
    if (p=strchr(a,'\n')) *p = '\0';
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
    int i=0, j, len, count=0;
    len = strlen(str1);
    do
    {
        count++;
        if (count == 4)
        {
            for (j=len; j>i; j--)
            {
                str1[j] = str1[j-1];
            }
            str1[i] = ch;
            count = 0;
        }
        i++;
        len++;
    } while (str1[i-1] != '\0');
    
    strcpy(str2, str1);
}