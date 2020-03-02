#include <iostream>
#include "head.h"
using namespace std;

class Point
{
    int x,y,z;
public:
    Point()
    {
        x=0;
        y=0;
        z=0;
    }
    friend istream& operator>>(istream&,Point&);
    friend ostream& operator<<(ostream&,Point&);
};


istream& operator>>(istream& in,Point &P)
{
    //in.ignore();
    in>>P.x;
    in>>P.y;
    in>>P.z;
    return in;
}

ostream& operator<<(ostream& out,Point &P)
{
    out<<"("<<P.x<<","<<P.y<<","<<P.z<<")";
    return out;
}

int main()
{
    Point p1,p2;
    cout<<"\nEnter the points x and y and z  ";
    cin>>p1;
    cout<<p1;
    cin>>p2;
    cout<<p3;
    Point p3;
    p3=p1+p2;
    cout<<p3;
    return 0;
}
