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
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
*/

TreeNode* insertIntoBST1(TreeNode* root, int val) {
    TreeNode* myNode = new TreeNode(val);
    TreeNode* curr = root;
    while(curr)
    {
        if(val<curr->val)
        {
            if(curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = myNode;
                return root;
            }
        }
        else
        {
            if(curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = myNode;
                return root;
            }
        }
    }
    return myNode;
}

// Alternate Solution
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == nullptr)
    {
        return new TreeNode(val);
    }

    if(val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
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

    root = insertIntoBST(root, 5); 

    return 0;
}





