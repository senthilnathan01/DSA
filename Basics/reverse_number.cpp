#include<iostream>
using namespace std;

int revNum(int n){
    int rev_num = 0;
    while(n>0){
        int last_digit = n%10;
        rev_num = rev_num*10 + last_digit;
        n /= 10;

    }
    return rev_num;
}

// Complexity AnalysisL:
// Time Complexity = O(log10(n))
// Space Complexity = O(1)

int main(){
    int n;

    cin>>n;
    cout<<"The original number is:"<<endl;
    cout<<n<<endl;
    cout<<"The reversed number is:"<<endl;
    cout<<revNum(n)<<endl;
    return 0;
}