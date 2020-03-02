#include <iostream>
using namespace std;

class Set
{
    int *set;
    int size;
    static int count=0;
    Set(int size)
    {
        set = new int[size];
    }
    ~Set();
    static void add(int);
};

Set::~Set()
{
    delete []set;
}

void Set::add(int x)
{
    set[++count]=x;
}

int main()
{
    return 0;
}
