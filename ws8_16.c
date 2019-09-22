#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter a string ");
    gets(str);
    int i;
    for(i=0; str[i];i++)
    {
        if(str[i]>= 'a' && str[i]<= 'z')
            str[i]=str[i]-32;
        else if(str[i]>= 'A' && str[i]<= 'Z')
            str[i]=str[i]+32;
    }
    printf("%s",str);
}
