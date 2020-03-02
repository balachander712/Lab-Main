#include <iostream>
#include "head.h"
using namespace std;

class Point
{
    public:
        int x,y;
        friend void operator -(Point&);
        void operator ++();
        void operator ++(int);
        void display(){cout<<x<<" "<<y;}
};
void operator -(Point &q)
{
    q.x=-q.x;
    q.y=-q.y;
}

void Point::operator ++()
{
    x=x+1;
    y=y+1;
}

void Point::operator ++(int)
{
    x=x+1;
    y=y+1;
}