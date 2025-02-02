#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

// Approach 1:
// Use this or the other approach based on the number of words in wordList and the size of each word
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Check if the endWord is in the wordList
        bool isPresent = false;
        for(auto word: wordList)
        {
            if(endWord == word)
            {
                isPresent = true;
                break;
            }
        }

        if(isPresent == false)
        {
            return 0;
        }

        int minTransform = 6000;

        // Initiate the queue
        queue<string> wordQueue;
        unordered_set<string> mySet;
        int layer = 1;
        compareStrings(beginWord, wordList, wordQueue, mySet);
        while(!wordQueue.empty())
        {
            layer++;
            int layerSize = wordQueue.size();
            for(int i = 0; i < layerSize; i++)
            {
                string word = wordQueue.front();
                wordQueue.pop();
                if(word == endWord) minTransform = min(minTransform, layer);
                compareStrings(word, wordList, wordQueue, mySet);
            }
            if(minTransform != 6000) return minTransform;
        }
        return 0;
    }

private:
    void compareStrings(string base, vector<string> &wordList, queue<string> &wordQueue, unordered_set<string> &mySet)
    {
        int len = base.length();
        int count = 0;
        for(auto word: wordList)
        {
            for(int i = 0; i < len; i++)
            {
                if(base[i] != word[i]) count++;
                if(count>1) break;
            }
            if(count == 1)
            {
                if(mySet.find(word)==mySet.end())
                {
                    wordQueue.push(word);
                    mySet.insert(word);
                } 
            }
            count = 0;
        }
    }   
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    Solution obj;
    cout<<obj.ladderLength(beginWord, endWord, wordList);
}

// OUTPUT:
// 5
// hit -> hot -> dot -> dog -> cog
