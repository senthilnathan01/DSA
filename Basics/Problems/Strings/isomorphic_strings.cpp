#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.
*/

bool isIsomorphic(string s, string t) {
    int size_1 = s.size();
    int size_2 = t.size();
    if(size_1 != size_2) return false; // Strings must have the same length. They are not isomorphic otherwise. 

    unordered_map<char, char> myMap;
    set<char> image; // To store the mapped elements so as to avoid two characters mapping to the same element
    
    for(int i = 0; i<size_1; i++)
    {
        if(myMap.find(s[i])!=myMap.end()) //The element is already present in the mapping
        {
            // If its mapping is not t[i]
            if(myMap[s[i]]!=t[i]) return false;
        }
        else //The element is not present in the mapping
        {
            // Check if t[i] is already mapped to something else
            if(image.count(t[i])>0) return false;
            else // Since t[i] is not mapped to anything else
            {
                myMap[s[i]] = t[i]; // Add the element to the myMap
                image.insert(t[i]); // Add t[i] to the set
            }
        }
    }
    return true;
}

int main()
{
    cout<<isIsomorphic("egg", "moo")<<endl;
    cout<<isIsomorphic("meow", "nuke")<<endl;
    cout<<isIsomorphic("poor", "rich")<<endl;
    cout<<isIsomorphic("badc", "baba")<<endl;
}

// OUTPUT:
// 1
// 1
// 0
// 0