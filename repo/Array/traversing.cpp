#include<iostream>
#include<math.h>
using namespace std;

void max_value(int arr[], int n){
    int max = arr[0];
    for(int i =1; i<n; i++){
        if(arr[i]>max) max= arr[i];

    }
    cout<<"The maximum element of the array is "<<max<<endl;
}

void min_value(int arr[], int n){
    int min = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i]<min) min = arr[i];
    }
    cout<<"The minimum element of the array is "<<min<<endl;
}

void avg_value(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum= sum+arr[i];
    }
    cout<<"The average value is "<<sum/n<<endl;
}

void total_value(int arr[], int n){
    int sum = 0;
     for(int i = 0; i<n; i++){
        sum = sum+arr[i];
     }
     cout<<"The total value is "<<sum<<endl;
}
void sin_value(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<"The sin value is of "<<arr[i]<<" is "<<sin(arr[i])<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    max_value(arr, n);
    min_value(arr, n);
    avg_value(arr, n);
    total_value(arr, n);
    sin_value(arr, n);
    
}