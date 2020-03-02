#include <iostream>
using namespace std;

class construct
{
    public:
        int a,b;

        construct()
        {
            a=10;
            b=20;
        }
};

int main()
{
    construct c;
    cout<<c.a<<"\n";
    cout<<c.b;

    return 1;
}
