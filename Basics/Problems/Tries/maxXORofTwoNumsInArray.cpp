/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
*/

struct TrieNode{
    TrieNode* children[2];
    TrieNode(){for(int i = 0; i < 2; i++) children[i]=nullptr;}
    

    bool containsKey(int bit){return (children[bit]!=nullptr);}
    TrieNode* get(int bit){return children[bit];}
    void put(int bit, TrieNode* node){children[bit]=node;}
};

class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){root = new TrieNode();}

    void insert(int num){
        TrieNode *node = root;
        for(int i = 31; i >=0; i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)) node->put(bit, new TrieNode());
            node = node->get(bit);
        }
    }

    int getMax(int num){
        TrieNode* node = root;
        int maxNum = 0;
        for(int i = 31; i >=0; i--){
            int bit = (num>>i) &1;
            if(node->containsKey(1-bit)){
                maxNum |= (1<<i);
                node = node->get(1-bit);
            }
            else node = node->get(bit);
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it: nums) trie.insert(it);
        int maxi = 0;
        for(auto it: nums) maxi = max(maxi, trie.getMax(it));
        return maxi;
    }
};
