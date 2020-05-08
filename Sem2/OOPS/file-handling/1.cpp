#include <iostream>
#include <iomanip>
#include <limits>


using namespace std;
int main(int argc, char** argv)
{
    char str[50];
    cout << setw(15) << left << 40000 << endl;

    cout<<"Enter the string ";
    cin.get(str,50);
    cin.clear();
    cin.ignore();

    cout << str << endl;


    cout << 200 << endl;
    cout << showpos << 200 << endl;
   
    cout << setw(9) << setfill('0') << 1.234 << endl;

}