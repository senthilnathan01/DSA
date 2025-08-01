/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Leetcode Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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
    vector<int> inorderTraversal(TreeNode* root) {
        // Left -> Root -> Right
        // Using Stacks
        if(root==nullptr) return {};

        vector<int> ans;

        stack<TreeNode*> s;
        TreeNode* current = root;

        while(current || !s.empty())
        {
            while(current)
            {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            ans.push_back(current->val);
            current = current->right;
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Left -> Root -> Right
        // Using Recursion
        if(!root) return {};

        vector<int> ans;
        inOrderRecursion(ans, root);
        return ans; 
    }

    void inOrderRecursion(vector<int> &ans, TreeNode *root)
    {
        // Base Case
        if(!root) return;

        // Recursive Case
        inOrderRecursion(ans, root->left);
        ans.push_back(root->val);
        inOrderRecursion(ans, root->right);
    }
};

