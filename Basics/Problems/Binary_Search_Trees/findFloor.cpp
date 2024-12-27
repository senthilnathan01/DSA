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
You are given a BST(Binary Search Tree) with n number of nodes and value x. 
your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.
*/

int floor(TreeNode* root, int x) {
    // Code here
    int floor = -1;
    while(root)
    {
        if(root->val == x) return x;
        else if(root->val < x )
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
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

    cout << floor(root, 5) << endl; 

    return 0;
}

// OUTPUT:
// 4



