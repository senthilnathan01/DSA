#include<iostream>
#include<string>

using namespace std;

/*
Given a string s, return the longest palindromic substring in s.
*/

bool isPalindrome(int i, string s){
    // Uses recursion
    if(i>=s.length()/2) return true;
    if(s[i]!=s[s.length()-i-1]) return false;
    return isPalindrome(i+1, s); 
}

string longestPalindrome(string s) {
    int longest = 0;
    int start = 0;
    int n = s.size();
    int i;
    for(i = 0; i< n ; i++)
    {
        if(longest < n-i){
            for(int j = n-1; j>=0; j--)
            {
                if(s[i]==s[j])
                {
                    int length = j-i+1;
                    if(longest<length)
                    {
                        if(isPalindrome(0, s.substr(i, length)))
                        {
                            longest = length;
                            start = i;
                            break;
                        }
                    }
                    else break;  
                } 
            }
        }
        else break;     
    }
    return s.substr(start, longest);
}

int main()
{
    string s = "babad";
    cout<<longestPalindrome(s)<<endl;
    s = "cbbd";
    cout<<longestPalindrome(s)<<endl;
}

// OUTPUT:
// bab
// bb