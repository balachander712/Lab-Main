#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100],temp[100];
    printf("Enter the string ");
    gets(str);
    int i=0,j=0;


    while(str[i]!= '\0')
    {
        if(str[i] !=' ')
        {
            temp[j]=str[i];
            j++;
        }
        else
        {
            temp[j]='\0';
            printf("%s",strrev(temp));
            printf(" ");
            j=0;
        }
        i++;
    }
    temp[j]='\0';
    printf("%s",strrev(temp));
}
