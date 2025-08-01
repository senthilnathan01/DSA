/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Leetcode Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
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
    vector<int> postorderTraversal(TreeNode* root) {
        // Using Recursion
        // Left -> Right -> Root
        if(!root) return {};

        vector<int> ans;
        postOrder(ans, root);
        return ans;

    }

    void postOrder(vector<int> &ans, TreeNode* root)
    {
        // Base Case
        if(!root) return;

        // Recursive Case
        postOrder(ans, root->left);
        postOrder(ans, root->right);
        ans.push_back(root->val);
    }
};

// Using Stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // Using Stacks
        if(!root) return {};

        // Left -> Right -> Root
        stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* current = s.top();
            s.pop();
            ans.insert(ans.begin(), current->val);

            if(current->left) s.push(current->left);
            if(current->right) s.push(current->right);            
        }
        return ans;
    }
};
