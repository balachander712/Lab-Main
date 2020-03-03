#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void eat()
    {
        cout<<"Generic food ";
    }
};

class cat:public Animal
{
public:
    void eat()
    {
        cout<<"Rat ";
    }
};

int main()
{
    Animal *a= new Animal;
    cat *c=new cat;
    a=c;
    a->eat();
    c->eat();
    cout<<sizeof(cat);
    return 0;
}
