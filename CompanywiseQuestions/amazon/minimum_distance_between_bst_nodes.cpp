/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

LINK: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
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
    int ans = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root){
        if(!root) return;
        // do for left subtree
        inorder(root->left);

        // get distance
        if(prev) ans = min(ans, root->val-prev->val);
        // update prev
        prev = root;

        // do for right subtree
        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
