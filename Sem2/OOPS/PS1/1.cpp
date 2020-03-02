#include <iostream>
using namespace std;

struct set
{
    int n;
    int *p;
};

void display(struct set s)
{
    int i;
    for(i=0;i<s.n;i++)
        cout<<s.p[i]<<" ";

    cout<<"\n";;
}

int main()
{
    struct set a,b;
    int i;
    cout<<"Enter the first structure size ";
    cin>>a.n;
    cout<<"Enter the second structure size ";
    cin>>b.n;
    b.p=new int(b.n);
    a.p=new int(a.n);
    cout<<"Enter the first set elements ";
    for(i=0;i<a.n;i++)
    {
        cin>>a.p[i];
    }
    cout<<"Enter the second set elements ";
    for(i=0;i<b.n;i++)
    {
        cin>>b.p[i];
    }
    display(a);
    display(b);
}

