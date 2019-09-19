#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[]="12345";
    int i,j,dec=0;
    for( i=0;i<strlen(str);i++)
    {
        dec=dec*10 + (str[i]-'0');
    }
    printf("%d",dec);
}
