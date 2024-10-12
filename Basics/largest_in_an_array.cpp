#include<iostream>
#include<algorithm>
using namespace std;

int largest(int arr[], int n){
    return *max_element(arr, arr+n);
}

int main(){
    int arr[] = {1, 10, 9, 54, 2, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Max element: "<< largest(arr, n);
    return 0;
}