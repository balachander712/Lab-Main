#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100],vow[100],con[100];
    int i,j=0,k=0;
    printf("Enter the string ");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='a'|| str[i]=='A'|| str[i]=='e'|| str[i]=='E'|| str[i]=='i'|| str[i]=='I'|| str[i]=='o'|| str[i]=='O'||
           str[i]=='u'|| str[i]=='U')
           {
               vow[j++]=str[i];
           }
        else
            con[k++]=str[i];
    }
    printf("%s\n",vow);
    printf("%s\n",con);
}
