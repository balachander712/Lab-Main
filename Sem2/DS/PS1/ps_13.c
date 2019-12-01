#include<stdio.h>
void main()
{
    char s[50];
    int i;
    printf("Enter a word ");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++);
    if(s[i-1]=='y')
    {
        s[i-1]='i';
        s[i]='e';
        s[i+1]='s';
    }
    else if(((s[i-2]=='c')&&(s[i-1]=='h'))||((s[i-2]=='s')&&(s[i-1]=='h')))
    {
        s[i-2]='e';
        s[i-1]='s';
    }
    else if(s[i-1]=='s')
    {
        s[i-1]='e';
        s[i]='s';
    }
    else
    {
        s[i]='s';
    }
    printf("The plural form of the given word is %s",s);
}
