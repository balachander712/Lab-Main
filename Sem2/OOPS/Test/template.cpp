#include <iostream>
#include <string>
using namespace std;

template<int N>
class Array
{
    int array[N];
public:
    int getSize() const {return N;}
};

int main()
{
    Array<5> array;
    cout << array.getSize() << endl;
}