#include <iostream>
#include <string>
using namespace std;


template<typename T,int N>
class Array
{
    T array[N];
public:
    int getSize() const {return N;}
};

int main()
{
    Array<int,5> array;
    cout << array.getSize() << endl;
}