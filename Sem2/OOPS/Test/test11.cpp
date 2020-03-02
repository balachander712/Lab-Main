#include <iostream>
using namespace std;


class Number
{
    int x;
public:
    Number()
    {
        x=10;
    }
    void display() const
    {
        cout<<increment();
        cout<<x;
    }
    int increment()
    {
        x++;
    }
};

int main()
{
    Number n;
    n.display();
    return 0;
}
