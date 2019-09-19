#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
     char str[100];
     printf("Enter a string ");
     scanf("%s",str);
     int i=0;
     for(i=0;i<strlen(str);i++)
     {
         if(str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='i' ||str[i]=='I' ||
            str[i]=='o' ||str[i]=='O' || str[i]=='u' ||str[i]=='U' )
            {
                str[i]='*';
            }
        else
        {
            str[i]='#';
        }
     }
     printf(str);
}
