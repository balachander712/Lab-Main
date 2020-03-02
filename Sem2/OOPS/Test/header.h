#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class Rational
{
    int m,n;
public:
    Rational()
    {
        m=0;
        n=1;
    }
    Rational(int g,int h)
    {
        m=a;
        n=b;
    }
    bool check(Rational x);
    void display();

};

bool Rational::check(Rational z)
{
    if(m==z.m&&n==z.n)
    return true
    else
    return false;
}
void Rational::display()
{
    cout<<m<<"/"<<n;
}


#endif // HEADER_H_INCLUDED
