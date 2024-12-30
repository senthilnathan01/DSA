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

/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftHeight = 0, rightHeight = 0;

        TreeNode *leftNode = root, *rightNode = root;

        while(leftNode)
        {
            leftHeight++;
            leftNode = leftNode->left;
        }

        while(rightNode)
        {
            rightHeight++;
            rightNode = rightNode->right;
        }

        if(leftHeight == rightHeight) return (1<<leftHeight)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);      
    }
};

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    Solution obj;
    cout<< obj.countNodes(root);

    return 0;
}

// OUTPUT:
// 7