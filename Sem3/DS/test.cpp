#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> v;
    v.push_back(10);
    v.push_back(54);
    v.push_back(12);
    v.push_back(1);
    v.push_back(65);
    v.push_back(6);
    vector< pair <int,int> > vect(v.size());

    for(int i = 0; i < v.size(); i++){
        vect[i].first = v[i], vect[i].second = i;
    }

    sort(vect.begin(),vect.end());

    for(int i = 0; i < vect.size(); i++){
        cout << vect[i].first << "," << vect[i].second << " ";
    }

    return 0;
}