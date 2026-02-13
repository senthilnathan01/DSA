/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

LINK: https://leetcode.com/problems/copy-list-with-random-pointer/description/
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // constraints say n can be 0
        if(!head) return nullptr;

        unordered_map<Node*, Node*> mp; // mapping original and copied nodes

        Node* temp = head;
        // just create copy nodes
        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;

        // assign next and random
        while(temp){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};

// More optimisation in space
class Solution {
public:
    string reorganizeString(string s) {
        // few observations:
        // 1.max freq of char <= (n+1)/2 else return ""
        // 2.place max freq char at first (strategy)
        // this gives a observation
        // first place along 0..2..4..(even places) and the remaining in the odd places
        // take care to place the last number according to n
        int n = s.size();
        vector<int> freq(26, 0);
        for(char c: s) freq[c-'a']++;

        int maxi = 0;
        for(int f: freq) maxi = max(maxi, f);
        if(maxi>(n+1)/2) return "";

        vector<pair<int, char>> chars;
        for(int i = 0; i < 26; i++) if(freq[i]>0) chars.push_back({freq[i], char('a'+i)});

        sort(chars.rbegin(), chars.rend());
        
        string ans(n, ' ');
        int idx = 0;
        for(auto &[f,c]: chars){
            while(f>0){
                ans[idx] = c;
                idx+=2;
                if(idx>=n) idx = 1;
                f--;
            }
        }
        return ans;

    }
};
