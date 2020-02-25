#include <stdio.h>

int gcd(int a, int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;

    if(a==b)
        return a;

    if(a>b)
        return gcd(a-b,b);

    return(a,b-a);
}

int main()
{
    int x,y;

    printf("Enter two nos ");
    scanf("%d%d",&x,&y);

    printf("%d",gcd(x,y));
}
