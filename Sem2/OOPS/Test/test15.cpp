#include <iostream>
using namespace std;

class Base
{
    protected:
        int i;
    public:
        Base(){i=5;}
        void display()
        {
            cout<<i;
        }
};

class derived:protected Base
{
    public:
        int j;
        Base::i;
        derived()
        {
            j=10;
        }
        void display()
        {
            cout<<j;
        }
};

int main()
{
    derived D;
    D.display();
}