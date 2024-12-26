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
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

bool isSameTree(TreeNode* root1, TreeNode* root2)
{
    if(root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if(root1->val != root2->val)
    {
        return false;
    }
    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

int main()
{
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << isSameTree(root1, root2) << endl;
    return 0;
}

// OUTPUT:
// 0
