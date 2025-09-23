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

// 2x time improvement by performing bidirectional BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Storing wordList contents in an unordered set for a quick loop
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // Check if the endWord is in the wordList
        if(dict.find(endWord)==dict.end()) return 0;

        // Bidirectional BFS initialization
        unordered_set<string> beginSet{beginWord}, endSet{endWord};
        int level = 1;
        int len = wordList[0].size();
        // Execution
        unordered_set<string> nextSet;
        while(!beginSet.empty() && !endSet.empty())
        {
            if(beginSet.size() > endSet.size()) swap(beginSet, endSet);
            nextSet.clear(); // Empty set
            for(string word: beginSet)
            {
                for(int i = 0; i < len; i++)
                {
                    char original = word[i];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if(endSet.find(word) != endSet.end()) return level + 1;
                        if(dict.find(word) != dict.end())
                        {
                            nextSet.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            beginSet = nextSet;
            level++;
        }
        return 0;
    }
};
