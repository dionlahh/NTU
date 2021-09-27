#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cipher(char *s);
void decipher(char *s);
int main()
{
   char str[80], dummychar, *p;
   int choice;

   printf("Select one of the following options: \n");
   printf("1: cipher() \n");
   printf("2: decipher() \n");
   printf("3: exit() \n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            scanf("%c",&dummychar);
            printf("Enter the string: \n");
            fgets(str, 80, stdin);
            if (p=strchr(str,'\n')) *p = '\0';
            printf("To cipher: %s -> ", str);
            cipher(str);
            printf("%s\n", str);
            break;
         case 2:
            scanf("%c",&dummychar);
            printf("Enter the string: \n");
            fgets(str, 80, stdin);
            if (p=strchr(str,'\n')) *p = '\0';
            printf("To decipher: %s -> ", str);
            decipher(str);
            printf("%s\n", str);
            break;
         default:
            break;
      }
   } while (choice < 3);
   return 0;
}
void cipher(char *s)
{
    int length, i;
	length = strlen(s);
	for (i=0; i<length; i++)
    {
        if(isalpha(*s))
        {
            if(islower(*s))
            {
                (*s)++;
                if (!isalpha(*s))
                    (*s) = 'a';
            }
            else
            {
                (*s)++;
                if (!isalpha(*s))
                    (*s) = 'A';
            }
        }
        s++;
    }
}
void decipher(char *s)
{
	/*edit*/
    int length, i;
	char *ptr;
	ptr = s;
	length = strlen(s);
	for (i=0; i<length; i++)
    {
        if(isalpha(*s))
        {
            if(islower(*s))
            {
                (*s)--;
                if (!isalpha(*s))
                    (*s) = 'z';
            }
            else
            {
                (*s)--;
                if (!isalpha(*s))
                    (*s) = 'Z';
            }
        }
        s++;
    }
}
