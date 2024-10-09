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

bool isPalindrome1(int n){
    // Reverse the whole number and check if it is same as the original number
    if(n<0 || (n!=0 && n%10 == 0)) return false;
    else if(n==0) return true;
    else{
        int temp = n;
        if(revNum(temp) == temp){
            return true;
        }
        else return false;
    }
}

// Complexity Analysis:
// Time Complexity = O(log10(n))
// Space Complexity = O(1)

bool isPalindrome2(int n){
    // Just reverse half of the number and check if it same as the remaining half
    if(n<0 || (n!=0 && n%10 == 0)) return false;
    else if(n==0) return true;
    else{
        int temp = n;
        int rev_num = 0;
        while(rev_num<temp){
            rev_num = rev_num*10 + temp%10;
            temp /= 10;
        }
        return (rev_num == temp || (temp == rev_num/10));
    }
}

// Complexity Analysis:
// Time Complexity = O(log10(n)/2) because we are just reversing half the digits of the number
// Space Complexity = O(1)

int main() {
    int number = 4554;

    if (isPalindrome2(number)) {
        cout << number << " is a palindrome." << endl;
    } 
    else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}