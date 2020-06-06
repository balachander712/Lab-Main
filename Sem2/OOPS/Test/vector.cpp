#include <iostream>
// Contigious memory
#include <vector>
#include <string>
// Doubly Linked list
#include <list>
#include <algorithm>
using namespace std;

int main(int argc,char** argv)
{
    vector<int> v;
    v.push_back(2320);
    v.push_back(20);
    v.push_back(3044);
    v.push_back(40);


    vector<int>::iterator itr = v.begin();
    sort(v.begin(), v.end());
    //sort(v.end(), v.begin());
    for(;itr != v.end();itr++)
    {
        cout << "The value is " << *itr << endl;
    }


    cout << "Size is " << v.size() << endl;

    v.clear();

    cout << "Size is " << v.size() << endl;

}