/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

LeetCode Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
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

// Using Recursion
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        return goodNodes(root, INT_MIN);
    }

    int goodNodes(TreeNode* root, int maxNum)
    {
        int curr = 0;
        if(root->val>=maxNum) curr = 1;
        int left = 0, right = 0;
        if(root->left) left = goodNodes(root->left, max(maxNum, root->val));
        if(root->right) right = goodNodes(root->right, max(maxNum, root->val));
        return left + right + curr;
    }
};
