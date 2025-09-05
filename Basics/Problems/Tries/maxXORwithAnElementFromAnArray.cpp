/*
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. 
In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

LINK: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
*/

struct TrieNode{
    TrieNode *children[2];

    TrieNode(){for(int i = 0; i < 2; i++) children[i]=nullptr;}

    bool containsKey(int bit){return children[bit];}
    void put(int bit, TrieNode* node){children[bit]=node;}
    TrieNode* get(int bit){return children[bit];}
};

class Trie{
    private:
    TrieNode* root;

    public:
    Trie(){ root = new TrieNode();}

    void insert(int num){
        TrieNode* curr = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!curr->containsKey(bit)) curr->put(bit, new TrieNode());
            curr = curr->get(bit);
        }
    }
    
    int getMaxXOR(int num){
        TrieNode* curr = root;
        if(!curr->children[0] && !curr->children[1]) return -1;

        int xorVal = 0;
        for(int i = 31; i >=0; i--){
            int bit = (num>>i)&1;
            int opp = 1-bit;
            if(curr->containsKey(opp)){
                xorVal |= (1<<i);
                curr=curr->get(opp);
            }
            else curr=curr->get(bit);
        }
        return xorVal;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<array<int, 3>> q;
        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i][0], queries[i][1], i});
        }
        sort(q.begin(), q.end(), [](auto &a, auto &b){ return a[1]<b[1];});

        Trie trie;
        vector<int> ans(queries.size());
        int idx =0;

        for(auto query: q){
            int x = query[0], m = query[1], i = query[2];

            while(idx < nums.size() && nums[idx]<=m){
                trie.insert(nums[idx]);
                idx++;
            }

            ans[i] = trie.getMaxXOR(x);
        }
        return ans;
    }
};
