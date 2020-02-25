#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],key[100];
    int i=0,j=0,k;
    printf("Enter the string\n");
    gets(str);
    printf("Enter the word\n");
    gets(key);
    for(i=0;i<strlen(str);i++)
    {
        while(str[i]==key[j]&&key[j]!='\0')
        {
            for(k=i;str[k]!='\0';k++)
            {
                str[k]=str[k+1];
                }
            j++;
        }
}
printf("string after the reverse is\n\n%s",str);
return 0;
}
