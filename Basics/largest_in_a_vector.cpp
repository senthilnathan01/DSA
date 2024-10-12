#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int largest(vector<int> &arr){
    return *max_element(arr.begin(), arr.end());
}
int main(){
    vector<int> arr = {1, 10, 9, 54, 2, 2};

    cout<<"Max element: "<< largest(arr);
    return 0;
}