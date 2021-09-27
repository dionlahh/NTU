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
	char max_value;
	char tmp;
	int i, j, length, pos;
	length = strlen(str);
	max_value = str[0];


	for (i=0; i<length; i++) //checks for the greatest ascii character
    {
        if (max_value < str[i])
        {
            max_value = str[i];
        }
    }

    for (i=0; i<length; i++) //get the position of the first occurrence of max_value
        if (str[i] == max_value)
        {
            pos = i;
            break;
        }

    for (i=pos; i>0; i--) //shifts string
    {
        str[i] = str[i-1];
    }
    str[0] = max_value; //append the first element as max_value
}
