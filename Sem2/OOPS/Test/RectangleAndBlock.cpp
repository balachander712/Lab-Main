#include <iostream>
using namespace std;

class Rectangle
{
    int length;
    int width;
public:
    Rectangle();
    void getdata();
    void putdata();
};

Rectangle::Rectangle()
{
    length=0;
    width=0;
}

void Rectangle::getdata()
{
    cout<<"\nEnter the length ";
    cin>>length;
    cout<<"\nEnter the width ";
    cin>>width;
}

void Rectangle::putdata()
{
    cout<<"\nThe length is "<<length;
    cout<<"\nThe width is "<<width;
}

class Block:public Rectangle
{
    int height;
public:
    Block();
    void getHeight();
    void putHeight();
};

Block::Block()
{
    height=0;
}

void Block::getHeight()
{   
    cout<<"\nEnter the height ";
    cin>>height;
}

void Block::putHeight()
{
    cout<<"\n The height is "<<height;
}


int main()
{   
    Rectangle r;
    Block  b;
    r.getdata();
    r.putdata();
    b.getHeight();
    b.putHeight();
    return 0;
}