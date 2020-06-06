#include <iostream>
using namespace std;

int main()
{
    int x,y;

    try{
        cin >> x >> y;

        if(y == 0)
            throw y;

        cout << "ans is " << x/y;
    }catch(int x){
        cout << "Division by zero is not possible";
    }


    return 0;
}