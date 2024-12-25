#include<iostream>

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

// Root Left Right
void preOrder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
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

    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;

    cout << "InOrder: ";
    inOrder(root);
    cout << endl;

    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;

    return 0;
}

// OUTPUT:
// PreOrder: 1 2 4 5 3 6 7
// InOrder: 4 2 5 1 6 3 7
// PostOrder: 4 5 2 6 7 3 1