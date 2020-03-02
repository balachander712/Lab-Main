#include <iostream>
using namespace std;

class Point
{
    int x,y;
public:
    Point()
    {
        x=0;
        y=0;
    }
    void getInput();
    void Display();
};

void Point::getInput()
{
    cout<<"\n Enter the value of x ";
    cin>>x;
    cout<<"\n Enter the value of y ";
    cin>>y;
}

void Point::Display()
{
    cout<<"\n x value is "<<x;
    cout<<"\n y value is "<<y;
}


int main()
{
    Point p;
    p.getInput();
    p.Display();
    return 0;
}