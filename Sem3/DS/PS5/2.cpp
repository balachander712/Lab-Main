#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, M;
    std::cout << "Enter the values of N and M " << endl;
    cin >> N >> M;
    int arr[N][M] = { 1,0,1,0,
                      0,1,0,0,
                      0,0,1,0,
                      0,0,1,1};

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cin >> arr[i][j];
    //     }
    // }

    int x = 0;

    for(int i = 1; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] > arr[x][j]){
                x = i;
                break;
            }
            else if(arr[i][j] < arr[x][j]) break;
        }
    }

    std::cout << x + 1 << endl;


    return 0;
}
