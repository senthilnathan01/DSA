#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].
Return an array of integers denoting the [floor, ceil]. 
Return -1 for floor or ceiling if the floor or ceiling is not present.
*/

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    // code here
    vector<int> ans;
    int low = 0;
    int high = arr.size()-1;
    // Sort the array
    sort(arr.begin(), arr.end());

    // Finds the floor of a given element in a sorted array.
    int floor = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<=x) low = mid + 1;
        else high = mid - 1;
    }
    if(arr[high]<=x) floor = arr[high];
    
    ans.push_back(floor);

    low = 0;
    high = arr.size()-1;
    
    // Finds the ceil of a given element in a sorted array.
    int ceil = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<=x) low = mid + 1;
        else high = mid - 1;
    }
    if(arr[low]>=x) ceil = arr[low];
    ans.push_back(ceil);

    return ans;     
}

int main() {
    vector<int> v = {10, 24, 69, 9};
    vector<int> ans = getFloorAndCeil(7, v);
    for(int num: ans){
        cout<<num<<" ";
    }
    return 0;
}

// OUTPUT:
// -1 9