/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.

LeetCode Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
*/

struct TrieNode{
    TrieNode* links[26];

    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch-'a']!= NULL;
    }

    void put(char ch, TrieNode* node)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    TrieNode* get(char ch)
    {
        return links[ch-'a'];
    }
};

class WordDictionary {
    private:
    TrieNode* root;

    bool dfs(string &word, int idx, TrieNode* node)
    {
        if(!node) return false;
        if(idx == word.length()) return node->isEnd();

        char ch = word[idx];
        if(ch=='.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(node->links[i] && dfs(word, idx+1, node->links[i])) return true;
            }
            return false;
        }
        else
        {
            if(!node->containsKey(ch)) return false;
            return dfs(word, idx+1, node->get(ch));
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch: word)
        {
            if(!node->containsKey(ch))
            {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(word, 0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
