#include<iostream>
using namespace std;

// Problem:
// Find the number of times the characters appear in the
// string = "abcdabefc"

// Using hashing

int main(){
    // First let us represent the alphabets in integer    
    // It is simple to do so as we already have a ASCII representation for the alphabets
    // For example: a -> 97,..., z -> 122

    int hash[256]={0}; // ASCII table has 256 elements
    string s = "abcdabefc";

    for(int i=0; i<s.size()-1; i++){
        hash[s[i]]+=1;
    }

    // Queries:
    int query_array[5]={'a', 'z', 'b','f', 'g'};

    for(int i=0; i<5; i++){
        cout<<hash[query_array[i]]<<" ";
    }
    return 0;
}

// Output: 2 0 2 1 0