#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Brute force approach

vector<int> print_divisors_1(int n){
    vector<int> divisors;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            divisors.push_back(i);
        }
    }
    return divisors;
}

// Complexity Analyis:
// Time complexity = O(N)
// Space complexity = O(N)

// Better approach

vector<int> print_divisors_2(int n){
    vector<int> divisors;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            divisors.push_back(i);
            if(i!=n/i){
                divisors.push_back(n/i);
            }
        }
    }
    return divisors;
}

// Complexity Analyis:
// Time complexity = O(sqrt(N))
// Space complexity = O(2*sqrt(N))

int main(){
    int n;
    cin>>n;

    vector<int> divisors_1 = print_divisors_1(n);
    vector<int> divisors_2 = print_divisors_2(n);

    cout<<"The divisors are"<<endl;
    for(int divisor: divisors_1){
        cout<<divisor<<" ";
    }

    cout<<endl<<"The divisors are"<<endl;
    for(int divisor: divisors_2){
        cout<<divisor<<" ";
    }
    return 0;
}