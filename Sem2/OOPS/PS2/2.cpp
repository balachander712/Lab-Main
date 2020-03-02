#include <iostream>
using namespace std;

int tripleByValue(int n)
{
    return 3*n;
}

int tripleByReference(int &n)
{
    n=3*n;
}

int main()
{
    int x=5;
    int &a=x;
    cout<<tripleByValue(x)<<"\n";
    tripleByReference(a);
    cout<<a;
}
