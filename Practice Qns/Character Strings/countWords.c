#include <stdio.h>
#include <string.h>
int countWords(char *s);
int main()
{
    char str[50], *p;
    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    printf("countWords(): %d", countWords(str));
    return 0;
}
int countWords(char *s)
{
    int i, len, count=1;
    len = strlen(s);
    for (i=0; i<len; i++)
    {
        if (s[i] == ' ')
            count++;
    }
    return count;
} 