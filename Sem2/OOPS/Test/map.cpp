#include<iostream>
#include<map>
using namespace std;

int main()
{
    //pair<int,int> p = make_pair(10,20);
    //cout << p.first << " " << p.second;

    map<int,int> mp;

    mp[1] = 100;
    mp[7] = 700;
    mp[9] = 200;

    mp.insert(make_pair(100,400));


    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}