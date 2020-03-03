#include <iostream>
using namespace std;

class Publication
{
    char *str;
    int price;
public:
    Publication();    
    void getdata();
    void putdata();
};

Publication:: Publication()
{
    price=0;
}

void Publication:: getdata()
{
    cout<<"Enter the size of the string ";
    int size;
    cin>>size;
    str= new char[size];
    cout<<"Enter the title ";
    cin>>str;
    cout<<"Enter the price ";
    cin>>price;
}

void Publication::putdata()
{
    cout<<"\nThe item is "<<str<<"and the price is "<<price;
}

class Book:public Publication
{
    int count;
public:
    Book()
    {
        count=0;
    }
    void getdata();
    void putdata();
};

void Book::getdata()
{
    cout<<"\nEnter the count ";
    cin>>count;
}

void Book::putdata()
{
    cout<<"\nThe count is "<<count;
}

class Tape:public Publication
{
    float time;
public:
    Tape()
    {
        time=0;
    }
    void getdata();
    void putdata();
};

void Tape::getdata()
{
    cout<<"\nEnter the time in minuites ";
    cin>>time;
}

void Tape::putdata()
{
    cout<<"\nThe time is "<<time;
}

int main()
{
    Publication p;
    Book b;
    Tape t;

    p.getdata();
    p.putdata();
    b.getdata();
    b.putdata();
    t.getdata();
    t.putdata();

    return 0;
}