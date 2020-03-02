#include <iostream>
using namespace std;

class Point
{
    public:
    int x,y;
    Point(){x=0;y=0;}
};

class Rational
{
    public:
    int x,y;
    Rational(){x=0;y=0;}
};

int main()
{
    Point P;
    P.x=10;
    P.y=10;
    Rational *R;
    R=(Rational*)&P;
    return 0;
}