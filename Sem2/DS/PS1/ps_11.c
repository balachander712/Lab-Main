#include<stdio.h>
void main()
{
    char s[100];
    int i,j;
    printf("Enter a name ");
    gets(s);
    printf("The name in abbreviated form ");
    printf("%c",s[0]);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==' ')
        {
            printf("%c",s[i+1]);
        }
    }
    printf("\n");
    printf("The name with initials ");
    printf("%c",s[0]);
    for(i=0;s[i]!=' ';i++);
    printf("%c",s[i+1]);
    for(i=i+1;s[i]!='\0';i++)
    {
        if(s[i]==' ')
        {
            for(j=i;s[j]!='\0';j++)
                printf("%c",s[j]);
        }
    }
}
