#include <iostream>
using namespace std;

int main()
{

    int x,y;

    try
    {
        cin >> x >> y;

        if(y == 0)
            throw 0;
        
        cout << "The ans is " << x/y << endl;
    }
    catch(const int x)
    {
        cout << "Division by zero not possible " << endl;
    }


    return 0;
}