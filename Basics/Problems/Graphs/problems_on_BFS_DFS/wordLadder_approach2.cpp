// Approach 2 for wordLadder.cpp

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
