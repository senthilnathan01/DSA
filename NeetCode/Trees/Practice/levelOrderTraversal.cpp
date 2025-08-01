/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

LeetCode Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();

            if(current == NULL)
            {
                ans.push_back(level);
                level.clear();
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                level.push_back(current->val);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
        }
        return ans;
    }
};
