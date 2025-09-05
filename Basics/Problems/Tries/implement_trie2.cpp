/*
Problem Statement: Implement a Trie data structure that supports the following methods:

Insert (word): To insert a string `word` in the Trie.
Count Words Equal To (word): Return the count of occurrences of the string word in the Trie.
Count Words Starting With (prefix): Return the count of words in the Trie that have the string “prefix” as a prefix.
Erase (word): Delete one occurrence of the string word from the Trie.
Note:

The Erase(word) function is guaranteed to be called only when a word is present in the Trie.
Release the memory associated with variables using dynamic memory allocation at the end of your solution.
*/

struct TrieNode{
    vector<TrieNode*> children;
    int cntEndsWith;
    int cntPrefix;

    TrieNode(): children(26, nullptr), cntEndsWith(0), cntPrefix(0){};

    bool containsKey(char c){return children[c-'a']!=nullptr;}
    TrieNode* get(char c){return children[c-'a'];}
    void put(char c, TrieNode* node){children[c-'a']=node;}
    void increaseEnd(){cntEndsWith++;}
    void increasePrefix(){cntPrefix++;}
    void deleteEnd(){cntEndsWith--;}
    void deletePrefix(){cntPrefix--;}
};

class Trie {
    private:
        TrieNode* root;

	public:
	    Trie() {root = new TrieNode();}

	    void insert(string word) {
	        TrieNode* curr = root;
            for(char c: word){
                if(!curr->containsKey(c)) curr->put(c, new TrieNode());
                curr = curr->get(c);
                curr->increasePrefix();
            }
            curr->increaseEnd();
    	}

	    int countWordsEqualTo(string word) {
	        TrieNode* curr = root;
            for(char c: word){
                if(curr->containsKey(c)) curr=curr->get(c);
                else return 0;
            }
            return curr->cntEndsWith;
    	}

	    int countWordsStartingWith(string word) {
	        TrieNode* curr = root;
            for(char c: word){
                if(curr->containsKey(c)) curr=curr->get(c);
                else return 0;
            }
            return curr->cntPrefix;  
    	}

	    void erase(string word) {
            if(word.empty()) return;
            
	        TrieNode* curr = root;
            for(char c: word){
                if(curr->containsKey(c)){
                    curr = curr->get(c);
                    curr->deletePrefix();
                }
                else return;
            }
            curr->deleteEnd();
	    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
