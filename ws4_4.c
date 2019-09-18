#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100],up[100]={0},lo[100]={0};
    printf("Enter a string :");
    scanf("%s",str);
    int i,j=0,k=0;
    for(i=0;i<strlen(str);i++)
    {
        up[j++]=toupper(str[i]);
        lo[k++]=tolower(str[i]);
    }
    printf("%s\n",up);
    printf("%s\n",lo);
}
