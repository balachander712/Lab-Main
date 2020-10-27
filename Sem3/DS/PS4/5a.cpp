#include<bits/stdc++.h>
#include<cmath>

using namespace std;

int partition(int arr[],int start, int end){
    
    int pivot = arr[start];
    int i = start;
    int j = end;
    
    while(i < j){

        while(i < j && arr[--j] >= pivot);
        //found the first element less than or equal to pivot
        if(i < j){
            arr[i] = arr[j];
        }

        while(i < j && arr[++i] <= pivot);
        //found the element greater than or equal to pivot
        if(i < j){
            arr[j] = arr[i]; 
        }
    }

    arr[j] = pivot;
    return j;

}

void quickSort(int arr[],int start,int end){
    if(end - start < 2) return;

    int pivotIndex = partition(arr,start,end);
    quickSort(arr,start,pivotIndex);
    quickSort(arr,pivotIndex + 1,end);
}

void print(int arr[],int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
	int n,k,t;
    cout << "Enter the total number of test cases " << endl;
	cin >> t;
	while(t--)
	{
        cout << "Enter the values of N and K " << endl;
		cin >> n >> k;

		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		quickSort(arr,0,n-1);
		double sum = 0.0;
		sum = (arr[n-1]-arr[1]+arr[n-2]-arr[0])*2.0;
        sum = sum + sqrt(2.0)*(arr[n-1]-arr[n-2]+arr[1]-arr[0]);
        long long rounded=ceil(sum);
        cout << "The minimum cost is " << endl;
        cout << rounded * k << endl;
	}


    return 0;
}