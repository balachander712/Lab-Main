#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& B,vector<int>& C,vector<int>& arr){
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;

    while(i < B.size() && j < C.size()){
        if(B[i] <= C[j]){
            arr[k++] = B[i++];
        }
        else{
            arr[k++] = C[j++];
            count += B.size() - i;
        }
    }

    while(i < B.size()){
        arr[k++] = B[i++];
    }

    while(j < C.size()){
        arr[k++] = C[j++];
    }

    return count;
}

int mergeSort(vector<int>& arr){

    int invCount = 0;
    int size = arr.size();

    if(size > 1){
        auto start = arr.begin();
        auto end = arr.end();
        auto mid = arr.begin() + size/2;
        vector<int> B(start,mid);
        vector<int> C(mid,end);
        invCount +=  mergeSort(B);
        invCount +=  mergeSort(C);
        invCount +=  merge(B,C,arr);
    }

    return invCount;

}

void print(vector<int> arr){
    for(auto itr : arr){
        cout << itr << " ";
    }
}

int main(){

    vector<int> arr = {8,4,2,1};
    cout << mergeSort(arr);
    return 0;
}