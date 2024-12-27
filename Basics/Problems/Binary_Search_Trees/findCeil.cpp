#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
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
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.
*/

int findCeil(TreeNode* root, int input)
{
    int ceil = -1;
    while (root)
    {
        if (root->val == input)
            return input;
        else if (root->val < input)
            root = root->right;
        else
        {
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}


int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    cout << findCeil(root, 5) << endl; // 6

    return 0;
}

// OUTPUT:
// 



