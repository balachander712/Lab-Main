#include <iostream>
using namespace std;

int fib(int n)
{
    if(n<=0)
        return n;
    else
        return fib(n-1)+fib(n-2);
}

int main()
{
    int n=5;
    int i,j=0;

    for(i=0;i<=n;i++)
    {
        cout<<fib(i);
        j++;
    }
}
