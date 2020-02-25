#include <stdio.h>

int Fun(int x)
{
    int res;
    if(x==0)
        return 1;

    else
    {
        res=(Fun(x-1)*x)+x;
        return res;
    }
}

int main()
{
    int n,ans;
    printf("Enter the number ");
    scanf("%d",&n);
    ans=Fun(n);
    printf("%d",ans);
}
