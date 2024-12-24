#include<iostream>
using namespace std;

void func(int l,int n, int arr[]){
    if(l>=n) return;
    swap(arr[l], arr[n-1]);
    func(l+1, n-1, arr);
}

int main(){
    int arr[5]={0,1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    func(0, n, arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
