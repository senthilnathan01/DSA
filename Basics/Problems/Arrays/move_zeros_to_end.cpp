#include <iostream>
#include <vector>

using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
    int non_zero_index = 0;
    for(int i=0; i<n; i++){
        if(a[i]!=0){
            a[non_zero_index++]=a[i];
        }
    }

    while(non_zero_index<n){
        a[non_zero_index++]=0;
    }
    return a;
}


int main() {
    vector<int> nums = {1, 2, 0, 3, 0, 4, 0, 5};

    nums = moveZeros(8, nums);

    for (int i = 0; i < 8; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}