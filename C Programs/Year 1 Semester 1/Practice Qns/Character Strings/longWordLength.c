#include <stdio.h>
#include <string.h>
#include <ctype.h>
int longWordLength(char *s);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
    int i, count = 0, len, max = 0;
    len = strlen(s);

    for (i=0; i<len; i++)
    {
        if (isalpha(s[i]))
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }    
        else
        {
            count = 0;
        }
    }
    return max;
} 