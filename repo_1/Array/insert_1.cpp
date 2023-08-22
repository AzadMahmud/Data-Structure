#include<bits/stdc++.h>
using namespace std;

void insert(int arr[], int n, int k){
    int low = 0;
    int high = n - 1;
    int insertionIndex;
    while(low<=high){
        int mid = (low + high)/2;
        if(k<arr[mid]) high = mid -1;
        else low = mid + 1;  
    }insertionIndex = low;
    for(int i = n - 1; i>= insertionIndex; i--){
        arr[i+1]= arr[i];
    }
    arr[insertionIndex] = k;

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }


}

int main(){
    int n, k;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element you to insert"<<endl;
    cin>>k;
    insert(arr, n, k);
}