#include<iostream> 
#include <cstring>

using namespace std;

/*
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 
*/

// 2 Approaches:

// Brute Force Approach with TC = O(n^2) and SC = O(1)

long long int substrCount1(string s, int k) {
    int n = s.size();
    long long result = 0;

    for (int i = 0; i < n; i++) {
        int char_count[26] = {0};
        int distinct_count = 0;

        for (int j = i; j < n; j++) {
            if (char_count[s[j] - 'a'] == 0) {
                distinct_count++;
            }
            char_count[s[j] - 'a']++;

            if (distinct_count == k) {
                result++;
            } else if (distinct_count > k) {
                break;
            }
        }
    }

    return result;
}

// Optimal Approach using Sliding Window

long long int atMostKs(string s, int k) {
    int n = s.size();
    int char_count[26] = {0};
    int distinct_count = 0;
    int i = 0;
    long long result = 0;

    for (int j = 0; j < n; j++) {
        char_count[s[j] - 'a']++;
        if (char_count[s[j] - 'a'] == 1) {
            distinct_count++;
        }

        while (distinct_count > k) {
            char_count[s[i] - 'a']--;
            if (char_count[s[i] - 'a'] == 0) {
                distinct_count--;
            }
            i++;
        }

        result += (j - i + 1);
    }

    return result;
}

long long int substrCount2(string s, int k) {
    return atMostKs(s, k) - atMostKs(s, k - 1);
}


int main()
{
    cout<<substrCount1("aba", 2)<<endl;
    cout<<substrCount2("aba", 2)<<endl;
    cout<<substrCount1("abaaca", 1)<<endl;
    cout<<substrCount2("abaaca", 1)<<endl;
}

// OUTPUT:
// 3
// 3
// 7
// 7
