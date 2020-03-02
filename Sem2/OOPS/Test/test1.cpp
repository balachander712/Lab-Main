#include <iostream>
using namespace std;

void swap(int *p_x,int *p_y)
{
    int temp;
    temp=&p_x;
    &p_x=&p_y;
    &p_y=temp;
    cout<<"The swapped numbers are "<<x<<" "<<y;
}

int main()
{
    int x,y;
    cout<<"Enter two nos ";
    cin>>x>>y;
    swap(&x,&y);
    cout<<"The swapped numbers are "<<x<<" "<<y;

    return 0;
}
