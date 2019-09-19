#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[200],str1[100],str2[100];
    printf("Enter a string ");
    gets(str);
    printf("Enter the first string to compare ");
    gets(str1);
    printf("Enter the second string to compare ");
    gets(str2);
    int len=strlen(str);
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len>(len1+len2))
    {
        printf("NO!!!>>>>>");
        exit(0);
    }
    else
    {

    }


}



