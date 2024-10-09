#include<iostream>
using namespace std;

// Brute Force Approach:

// We iterate through all numbers from 1 up to the minimum of the two input numbers, 
// checking if each number is a common factor of both input numbers.

int findhcf_1(int a, int b){
    if(a==0) return b;
    else if(b==0) return a;
    else{
        int hcf = 1;
        for(int i=1; i<=min(a, b); i++){
            if(a%i == 0 && b%i == 0){
                hcf = i;
            }
        }
        return hcf;
    }

}
// Complexity Analysis:
// Time Complexity = O(min(N1, N2))
// Space Complexity = O(1)

// Better Approach:

// If we iterate from the minimum of N1 and N2 down to 1, we reduce the number of 
// iterations because we start from the potentially largest common factor and work downwards.

// The time complexity of this approach remains O(min(N1, N2)) but in practice, 
// it will execute fewer iterations on average.

int findhcf_2(int a, int b){
    if(a==0) return b;
    else if(b==0) return a;
    else{
        for(int i=min(a, b); i>=1; i--){
            if(a%i == 0 && b%i == 0){
                return i;
            }
        }
    }
}

// Complexity Analysis:
// Time Complexity = O(min(N1, N2))
// Space Complexity = O(1)

// Optimal Approach:

// The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. 
// It operates on the principle that the GCD of two numbers remains the same even if 
// the smaller number is subtracted from the larger number.

int findhcf(int a, int b){
    if(a==0) return b;
    else if(b==0) return a;
    else{
        while(a>0 && b>0){
            if(a>b) a = a%b;
            else b = b%a;
        }
        if(a==0) return b;
        else return a;
    }
}

int main(){
    int a = 15, b =20;
    cout<<"The hcf of "<<a<<" and "<<b<<" is: "<<findhcf(a, b)<<endl;
    return 0;
}