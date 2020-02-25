#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter the string ");
    scanf("%s",str);
    int i;
    int upper=0,lower=0;

    for(i=0;i<strlen(str);i++)
    {
        if(isupper(str[i]))
            upper++;
        else if(islower(str[i]))
            lower++;

    }
    int spl=strlen(str)-(upper+lower);
    printf("%d %d %d ",upper,lower,spl);
}
