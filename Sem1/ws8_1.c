#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[100];
    int i;
    printf("Enter the String :");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        printf("%c\n ",str[i]);
    }
}

