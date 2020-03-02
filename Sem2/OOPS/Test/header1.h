#include "header.h"

class Rat
{
    Rational S[100];
    int count;
public:
    Rat()
    {
        count=-1;
    }
    Rat Intersection(Rat x);
    void insert(Rational x);
    void remove(Rational y);
    void display_set();
};

Rat Rat::Union(Rat x)
{
    Rat temp;
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<=x.count;j++)
        {
            if(S[i].check(x.S[j]))
                temp.insert(S[i]);
        }
    }
    return temp;

}

void Rat::insert(Rational x)
{
    if(count+1==100)
    {
        cout<<"Set Full ";
        return;
    }
    else
    {
        count++;
        q[count]=x;
        display_set();
    }
}

void Rat::remove(Rational y)
{
    if(count==-1)
    {
        cout<<"Set Empty ";
        return;
    }
    else
    {
        for(i=0;i<count;i++)
        {
            if(S[i].check(y))
            {
                for(int j=1;j<count;j++)
                        S[i]=S[i+1];
                count--;
            }
        }
    }
}
void Rat::display_set()
{
    for(int i=0;i<count;i++)
        S[i].disp();
}
