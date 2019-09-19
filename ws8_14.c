#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter the string ");
    gets(str);
    printf("enter the character to be removed");
    char ch;
    scanf("%c",&ch);
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i]==ch)
        {

            str[i]=str[i+1];
            i--;
        }
        i++;

    }
    printf("%s",str);
}
