#include<iostream>
#include<vector>
using namespace std;

vector<int> func(int n){
    vector<int> numbers;
    int temp=1;
    for(int i=1; i<=n; i++){
        temp *= i;
        if(temp<=n) numbers.push_back(temp);
        else return numbers;
    }
    
    return numbers;
}
int main(){
    int n;
    cin>>n;
    vector<int> numbers = func(n);
    for (int number: numbers){
        cout<<number<<" ";
    }
    return 0;
}