#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to extract individual digits of a number and store them in a vector
vector<int> extractDigits(int N) {
    // Initialize an empty vector to store the digits
    vector<int> extracted_digits;  
    
    // Loop to extract digits until N becomes 0
    while(N > 0){
        // Extract the last digit of N
        int lastDigit = N % 10;  
        // Store the last digit in the vector
        extracted_digits.push_back(lastDigit); 

        // Remove the last digit from N
        N = N / 10; 
    }
    
    // reverse function used here requires <algorithm> header
    // Reverse the vector to get digits in the correct order
    reverse(extracted_digits.begin(), extracted_digits.end());  
    
    // Return the vector containing individual digits
    return extracted_digits; 
}


int main() {
    int N = 3298;

    cout << "N: "<< N << endl;

    vector<int> digits = extractDigits(N);

    cout << "Extracted Digits: ";
    for(auto num: digits){
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
                            
                        