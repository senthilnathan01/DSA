/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
The tree tree could also be considered as a subtree of itself.

Leetcode Link: https://leetcode.com/problems/subtree-of-another-tree/description/
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        return isSameTree(root, subRoot) 
        || isSubtree(root->left, subRoot) 
        || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2) return true;
        if(root1 && !root2) return false;
        if(root2 && !root1) return false;

        if(root1->val == root2->val)
        {
            return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
        }
        else return false;
    }
};
