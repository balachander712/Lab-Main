#include <iostream>
using namespace std;

class Example
{
    int x;
public:
    Example()
    {
        x=10;
    }

};

void main()
{
    Example ex;
    int *x=(int*)&ex;
    cout<<*x;
}