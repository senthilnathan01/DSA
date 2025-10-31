/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. 
You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a 
string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

LINK: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* node, int value, string &path){
        if(node==NULL) return false;
        if(node->val == value) return true;

        path += 'L';
        if(getPath(node->left, value, path)) return true;
        path.pop_back();

        path += 'R';
        if(getPath(node->right, value, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        if(!getPath(root, startValue, pathToStart)) return "";
        if(!getPath(root, destValue, pathToDest)) return "";

        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) i++;

        string up(pathToStart.size()-i, 'U');
        return up + pathToDest.substr(i); 
    }
};
