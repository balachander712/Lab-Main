#include <stdio.h>

int numpalindrome(int n)
{
    int rev=0;

    while(n!=0)
    {
        rev=rev*10;
        rev=rev+ n%10;
        n=n/10;
    }

    return rev;
}

        int i;
        int count=0;




int Isvowel(char *ptr)
{
    int count=0;

    while(*ptr != '\0')
    {
        if(*ptr=='a' ||*ptr=='e' ||*ptr=='i' ||*ptr=='o' ||*ptr=='u' )
        {
            count++;
        }

        *ptr++;
    }

    return count;
}

int main()
{
    int n;
    printf("Enter the number ");
    scanf("%d",&n);

    int rev=numpalindrome(n);

    if(rev==n)
    {
        printf("The number is a palindrome ");
    }

    else
    {
        printf("The number is not a palindrome ");
    }

    char str[100];

    printf("Enter the string ");
    gets(str);

    printf("%d",Isvowel(str));
    return 0;
}
