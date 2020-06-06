#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int,int> mp;

    mp.insert(make_pair(4,1000));
    mp.insert(make_pair(5,100));
    mp.insert(make_pair(1,20));
    mp.insert(make_pair(9,8));


    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "---->" << it->second << endl; 
    }


}