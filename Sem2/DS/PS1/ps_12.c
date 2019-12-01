
#include<stdio.h>
void main()
{
    char a[50],b[50];
    int i,f=0;
    printf("Enter the first string ");
    scanf("%s",a);
    printf("Enter the second string ");
    scanf("%s",b);
    for(i=0;i<50;i++)
    {
        if(a[i]==b[i])
        {
            printf("%c",a[i]);
            f++;
        }
        else
        {
            break;
        }
    }
    if(f==0)
        printf("There is no common prefix");

}
