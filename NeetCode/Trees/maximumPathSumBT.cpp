/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

LeetCode Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
    int res = INT_MIN;

    int getMax(TreeNode* root)
    {
        if(!root) return 0;
        int left = getMax(root->left);
        int right = getMax(root->right);
        return max(0, root->val + max(left, right));
    }

    void dfs(TreeNode* root)
    {
        if(!root) return;
        int left = getMax(root->left);
        int right = getMax(root->right);
        res = max(res, root->val + left + right);
        dfs(root->left);
        dfs(root->right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};

// Better
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = root->val;
        pathsum(root, sum);
        return sum;
    }

    int pathsum(TreeNode* node, int& sum)
    {
        if(node==NULL) return 0;
        int ls = max(0, pathsum(node->left, sum));
        int rs = max(0, pathsum(node->right, sum));  
        sum = max(sum, node->val + ls + rs);
        return node->val + max(ls,rs);
    }
};

