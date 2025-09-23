/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

LINK: https://leetcode.com/problems/word-ladder/description/
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();

            if(word == endWord) return steps;

            for(int i = 0; i < word.size(); i++){
                string temp = word;
                for(char ch = 'a'; ch <='z'; ch++){
                    temp[i] = ch;
                    if(st.count(temp)){
                        q.push({temp, steps+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
