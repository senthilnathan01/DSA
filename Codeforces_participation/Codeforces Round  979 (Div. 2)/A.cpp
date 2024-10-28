#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int score(vector<int> arr, int n){
    vector<int> b;
    vector<int> c;

    if(n>=2){
        return (n-1)*(*max_element(arr.begin(), arr.end())- *min_element(arr.begin(), arr.end()));
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i = 0; i<n; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        cout<<score(arr, n)<<endl;
    }
}