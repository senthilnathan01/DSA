/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

LeetCode Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/
*/

// Node structure for Trie
struct Node{
    // Array to store links to child nodes
    Node *links[26];

    // flag indicating if the node marks the end of the word
    bool flag = false;

    // Check if the node contains a specific key
    bool containsKey(char c){ return (links[c-'a'] != NULL);}

    // Insert a new node with letter into the Trie
    void put(char c, Node* node) {links[c-'a'] = node;}

    // Get the Node with specific letter from the Trie
    Node* get(char c) {return links[c -'a'];}

    // Set the current Node as the end of the word
    void setEnd() {flag = true;}  

    // Check if the current node marks the end of the word
    bool isEnd() {return flag;}
};

class Trie {
private: 
    Node* root;

public:
    Trie() { root = new Node();}
    
    void insert(string word) {
        Node* node = root;
        for(char c: word)
        {
            if(!node->containsKey(c)) node->put(c, new Node());
            node = node->get(c); 
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(char c: word)
        {
            if(!node->containsKey(c)) return false;
            node = node->get(c);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(char c: prefix)
        {
            if(!node->containsKey(c)) return false;
            node = node->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
