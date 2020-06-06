#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {100,20,400,30,60,4,90};
    int *begin = &arr[0];
    int *end = &arr[0] + (sizeof(arr)/sizeof(int));
    
    sort(begin,end);

    for(;begin != end; begin++)
    {
        cout << "Value is " << *begin << endl;
    }
}