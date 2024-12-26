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

int height(TreeNode* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    int leftDepth = height(root->left);
    int rightDepth = height(root->right);

    return max(leftDepth, rightDepth) + 1;
}  

bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(rh-lh)>1) return false;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    if(!left || !right) return false;
    return true;
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

    cout<<isBalanced(root);

    return 0;
}

// OUTPUT:
// 1
