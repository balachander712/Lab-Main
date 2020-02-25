#include <stdio.h>

int Fibonacci(int x)
{
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else
        return Fibonacci(x-1) + Fibonacci(x-2);

}

int main()
{
    int n,i=0,k;

    printf("Enter the number of terms ");
    scanf("%d",&n);

    for(k=0;k<=n;k++)
    {
        printf("%d ",Fibonacci(i));
        i++;
    }
}
