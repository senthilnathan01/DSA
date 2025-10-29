/*
You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. 
You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. 
More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

LINK: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/
*/
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](auto &a, auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            else return a[0]>b[0];
        });

        int ans = 0;
        int maxTillNow = INT_MIN;

        for(auto &p: properties){
            if(maxTillNow>p[1]) ans++;
            else maxTillNow = p[1];
        }
        return ans;
    }
};
