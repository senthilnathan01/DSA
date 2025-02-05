#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespacce std;

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList 
is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest
transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. 
Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
*/

// One way to write:
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Create an unordered set of wordList for quick look ups
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If the endWord is not the wordList then return {}
        if(wordSet.find(endWord) == wordSet.end()) return {};

        // Store parents for each word to reconstruct the path later
        unordered_map<string, vector<string>> parents;

        // Keep track of levels to ensure we only expand the shortest paths
        unordered_map<string, int> levels;

        queue<string> q;
        q.push(beingWord);
        levels[beginWord] = 0;

        int level = 0;
        bool found = false;
        unordered_map<string, vector<string>> newParents;
        while(!q.empty() && !found)
        {
            int size = q.size();
            newParents.clear(); // Empty set for new parents
            for(int i = 0; i < size; i++)
            {
                string word = q.front();
                q.pop();
                string originalWord = word;
                for(int j = 0; j < word.size(); j++)
                {
                    char originalChar = word[j];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        if(c == originalChar) continue;
                        word[j] = c;
                        if(wordSet.find(word) != wordSet.end())
                        {
                            if(levels.find(word) == levels.end() || levels[word] == level + 1)
                            {
                                if(levels.find(word) == levels.end())
                                {
                                    q.push(word);
                                    levels[word] = level + 1;
                                }
                                newParents[word].push_back(originalWord);
                            }
                        }
                    }
                    word[j] = originalChar;
                }
            }
            for(auto &p : newParents)
            {
                parents[p.first].insert(parents[p.first].end(), p.second.begin(), p.second.end());
            }
            level++;
        }

        vector<vector<string>> results;
        if(parents.find(endWord) == parents.end()) return results;

        vector<string> path;
        function<void(string)> dfs = [&](string word)
        {
            path.push_back(word);
            if(word == beginWord)
            {
                results.push_back(vector<string> (path.rbegin(), path.rend()));
            }
            else
            {
                for (const string &parent: parents[word]) dfs(parent);
            }
            path.pop_back();
        };

        dfs(endWord);
        return results;
    }

};

// Another way to write:
class Solution2 {
public:
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    // Approach:
    /*
    BFS for Shortest Path:

    - Use BFS to explore all possible transformations from the beginWord.
    - Maintain a depthMap to record the minimum number of transformations required to reach each word.
    - If the endWord is reached during BFS, the search stops, and the depth of the endWord is noted.
    
    DFS for Path Construction:

    - Once the BFS is complete, use DFS to backtrack from the endWord to the beginWord, constructing 
    all valid paths that match the minimum transformation depth recorded in depthMap.
    - Each valid path is stored in the result list.
    */
    unordered_map<string, int> depthMap;
    vector<vector<string>> ans;

    // BFS to find the shortest path
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);
    depthMap[beginWord] = 1;
    wordSet.erase(beginWord);

    while(!q.empty())
    {
        string word = q.front();
        q.pop();
        int steps = depthMap[word];
        if (word == endWord) break;
        for(int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if(wordSet.count(word))
                {
                    q.push(word);
                    wordSet.erase(word);
                    depthMap[word] = steps + 1;
                }
            }
            word[i] = original;
        }
    }

    // DFS to find all paths
    if (depthMap.count(endWord))
    {
        vector<string> seq = {endWord};
        dfs(endWord, beginWord, seq, depthMap, ans);
    }

    return ans;
}

private:
void dfs(string word, string beginWord, vector<string> &seq, unordered_map<string, int> &depthMap, vector<vector<string>> &ans)
{
    if(word == beginWord)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }

    int steps = depthMap[word];
    for(int i = 0; i < word.size(); i++)
    {
        char original = word[i];
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if(depthMap.count(word) && depthMap[word] + 1 == steps)
            {
                seq.push_back(word);
                dfs(word, beginWord, seq, depthMap, ans);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}
};
