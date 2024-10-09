#include<iostream>
#include<cmath>
using namespace std;

int count_digits(int n){
    return log10(n)+1;
}

bool isArmstrong(int n){
    // Get the number of digits
    int k = count_digits(n);
    cout<<k<<endl;
    int sum = 0;
    int temp = n;
    while(temp>0){
        sum += powf(temp%10, k);
        temp /= 10;
    }
    return sum == n ? true:false;
}

int main(){
    int n;
    cin>>n;
    if(isArmstrong(n)) cout<<"It is an armstrong number."<<endl;
    else cout<<"It is not an armstrong number."<<endl;
    return 0;
}