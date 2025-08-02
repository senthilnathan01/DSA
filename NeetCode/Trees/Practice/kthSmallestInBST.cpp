/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

LeetCode Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while(curr || !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            count++;
            if(count == k) return curr->val;

            curr = curr->right;
        }

        return -1;
    }
};
