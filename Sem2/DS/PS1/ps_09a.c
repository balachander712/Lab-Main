#include<stdio.h>
#include<string.h>
void main()
{
    int n,len,i;
    char str[100];
    printf("Enter the encoded line of text:\n");
    scanf("%[^\n]s",str);
    printf("Enter the integer: ");
    scanf("%d",&n);
    len=strlen(str);
    for(i=0;i<len;i++)
        str[i]-=n;
    printf("The original line of text is %s\n",str);
}
