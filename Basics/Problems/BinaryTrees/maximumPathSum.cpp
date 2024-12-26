#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/
int pathsum(TreeNode* node, int& sum)
{
    if(node == nullptr)
    {
        return 0;
    }
    int left = max(0, pathsum(node->left, sum));
    int right = max(0, pathsum(node->right, sum));
    sum = max(sum, left + right + node->val);
    return max(left, right) + node->val;
}

int maxPathSum(TreeNode* root)
{
    int sum = INT32_MIN;
    pathsum(root, sum);
    return sum;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root) << endl;
    return 0;
}

// OUTPUT:
// 18
