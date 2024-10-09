#include<iostream>
#include<cmath> //log10 requires this
using namespace std;

// Brute force approach
int count_digits_1(int n){
    int cnt = 0;
    while(n > 0){
        cnt += 1;
        n /= 10;
    }
    
    return cnt;
}

// Complexity Analysis:
// Time Complexity: Because the it takes log_10(n) number of iterations to reduce the number to 0,
// the time complexity if O(log10(n))

// Space Complexity:
// Space complexity: We store only the count of the number of digits
// Hence the complexity is O(1)

// Optimal Approach
int count_digits_2(int n){
    return log10(n)+1;
}

// Complexity Analysis: 
// Time Complexity: O(1)
// Space Complexity: O(1)

// One more approach is to convert the number to a string and use length() function
int count_digits_3(int n){
    int cnt;
    return cnt = to_string(n).length();
}

int main(){
    int n;
    cin >> n;
    cout << "The number of digits are: " << count_digits_1(n) << endl;
    cout << "The number of digits are: " << count_digits_2(n) << endl;
    cout << "The number of digits are: " << count_digits_3(n) << endl;     
    return 0;
}
