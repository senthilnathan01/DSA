/*
Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Leetcode Link: https://leetcode.com/problems/balanced-binary-tree/description/
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
    bool isBalanced(TreeNode* root) {
        // Trivial Case
        if(!root) return true;

        int lh = height(root->left), rh = height(root->right);
        if(abs(rh-lh)>1) return false;

        if(!isBalanced(root->left) || !isBalanced(root->right)) return false;

        return true;
    }

    int height(TreeNode* root)
    {
        if(!root) return 0;

        return max(height(root->left), height(root->right)) + 1;
    }
};
