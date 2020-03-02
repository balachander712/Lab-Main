#include <iostream>
using namespace std;

class Point
{
    public:
        char *arr;
        int x,y;
        Point()
        {
            this->x=0;
            this->y=0;
            char *arr=new char[20];
        }
        Point(int x,int y)
        {
            this->x=x;
            this->y=y;
        }
        Point operator +(Point&);
        Point& operator =(Point&);
        void display(Point);
};
Point& Point::operator = (const Point &p )
{
    delete [] arr;
    arr=new char[20];
    if(!this==&p)
    {
        x=p.x;
        y=p.y;
    }
    return *this;
}

Point& Point::operator =(const Point &p)
{
    delete [] arr;
    arr= new char[20];
    if(!this==&p)
    {
        x=p.x;
        y=p.y;
    }
    return *this;
}

Point Point::operator +(Point& p)
{
    Point p3;
    p3.x=this->x+p.x;
    p3.y=this->y+p.y;

    return p3;
}

void display(Point p)
{
    cout<<p.x<<" "<<p.y;
    cout<<p.arr;
}

int main()
{
    Point p1(10,20);
    Point p2(30,40);
    p2.arr="Constructor";
    Point p3;
    p3=p2;
    display(p3);

    return 0;
}