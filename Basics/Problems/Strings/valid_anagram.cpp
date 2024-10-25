#include<iostream>
#include<unordered_map>
using namespace std;

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

bool isAnagram(string s, string t) {
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;

    for(char character : s) map1[character]++;
    for(char character : t) map2[character]++;

    for(auto& pair : map1)
    {
        if(map1[pair.first]!=map2[pair.first]) return false;
    }
    for(auto& pair : map2)
    {
        if(map1[pair.first]!=map2[pair.first]) return false;
    }
    return true;
}


int main()
{
    string s = "anagram";
    string t = "nagaram";

    cout<<isAnagram(s, t)<<endl;
}

// OUTPUT:
// 1