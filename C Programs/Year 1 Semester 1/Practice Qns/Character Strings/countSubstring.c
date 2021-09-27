#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1 
int countSubstring(char str[], char substr[]);
int main()
{
    char str[80], substr[80], *p;
    int result=INIT_VALUE;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p = '\0';
    printf("Enter the substring: \n");
    fgets(substr, 80, stdin);
    if (p=strchr(substr,'\n')) *p = '\0';
    result = countSubstring(str, substr);
    printf("countSubstring(): %d\n", result);
    return 0;
}
int countSubstring(char str[], char substr[])
{
    char *s1 = str, *s2 = substr;
    int result=0, count=0;

        while (*s1)
        {
            if (*s1==*s2)
            {
                result = 1;
                s1++;
                s2++;
            }
            else
            {
                result = 0;
                s1++;
                s2 = substr;
            }

            if (*s2=='\0' && result==1)
            {
                count++;
                s2 = substr;
            }
        }

    return count;
} 