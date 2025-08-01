/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Leetcode Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
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

// Solution 1: Using Stacks
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // Root -> Left -> Right
        // Trivial Case
        if(root==nullptr) return {};

        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            TreeNode* current = s.top();
            s.pop();
            ans.push_back(current->val);

            if(current->right) s.push(current->right);
            if(current->left) s.push(current->left);
        }
        return ans;
    }
};

// Solution 2: Recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // Root -> Left -> Right
        // Trivial Case
        if(root==nullptr) return {};

        vector<int> ans;
        preOrderRecursion(ans, root);
        return ans;
    }   

    void preOrderRecursion(vector<int> &ans, TreeNode* root)
    {
        // Base Case
        if(root==nullptr) return;

        // Recursive Case
        ans.push_back(root->val);
        preOrderRecursion(ans, root->left);
        preOrderRecursion(ans, root->right);
    }
};
