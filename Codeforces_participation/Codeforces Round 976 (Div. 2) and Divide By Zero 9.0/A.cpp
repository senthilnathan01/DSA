#include<iostream>
using namespace std;

int divide_by_k(int n, int k, int count){
    if(k==1){
        return n/k;
    }
    else{
        while(n>0){
            while(n%k==0){
                n = n/k;
            }
            count += n%k;
            n = n - n%k;
        }
        return count;
    }
}

int main(){
    int test_cases;
    cin>>test_cases;

    for(int i=0; i<test_cases; i++){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int count=0;

        cout<<divide_by_k(n, k, count)<<endl;
    }
    return 0;
}