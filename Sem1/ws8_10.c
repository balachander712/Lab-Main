#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[]="Hello";
    int i,j;
    for(i=strlen(str);i>=0;i--)
    {
        for(j=0;j<i;j++)
            printf("%c",str[j]);
        printf("\n");
    }
}
