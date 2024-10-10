#include<iostream>
#include<cmath>
using namespace std;

// Just like we saw in printing the divisors of a number, 
// it is sufficient to only check for divisors that are equal to or less than the square root of a number

bool is_prime(int n){
    if(n == 1) return false;
    else{
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0) return false;
        }
        return true;
    }

}

int main(){
    int n;
    cin>>n;
    string result;
    if(is_prime(n)) result = " is a prime number.";
    else result = " is not a prime number";
    cout<<"The number "<<n<<result<<endl;
}