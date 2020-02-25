#include <stdio.h>

int sum(int x)
{
    int ans;
    if(x==0)
        return 0;

    else
    {
        ans= sum(x-1)+x;
        return ans;
    }

}

int main()
{
    int n;
    printf("Enter the value of n ");
    scanf("%d",&n);

    int res=sum(n);

    printf("%d",res);
}

//Itrative function for the same
/*int main()
{
    int n,i;
    int sum=0;

    printf("Enter the number ");
    scanf("%d",&n);
    for( i=0;i<=n;i++)
    {
        sum=sum+i;
    }

    printf("%d",sum);
}*/
