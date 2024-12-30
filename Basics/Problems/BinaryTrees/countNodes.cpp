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

class Solution {
public:
    void countMe(TreeNode* node, int& cnt)
    {
        cnt++;
        if(node->left != nullptr) countMe(node->left, cnt);
        if(node->right != nullptr) countMe(node->right, cnt);
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int cnt = 0;
        countMe(root, cnt);
        return cnt;
    }

    // Or alternatively just this function will work
    int countNodes2(TreeNode* root)
    {
        if(root==nullptr) return 0;
        return 1 + countNodes2(root->left) + countNodes2(root->right);
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
