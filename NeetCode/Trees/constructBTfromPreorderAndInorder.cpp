/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, construct and return the binary tree.

LeetCode Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);

        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftPre(preorder.begin()+1, preorder.begin() + mid + 1);
        vector<int> rightPre(preorder.begin()+mid+1, preorder.end());

        vector<int> leftIn(inorder.begin(), inorder.begin()+mid);
        vector<int> rightIn(inorder.begin()+mid+1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};
