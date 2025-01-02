#include<iostream>
#include<stack>
#include<vector>

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
You are given root node of the BST and the key node of the tree. You need to find the in-order successor and predecessor of a given key. 
If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 
*/

class Solution
{
public:
    void findPreSuc(TreeNode* root, TreeNode*& pre, TreeNode*& suc, int key)
    {
        // Base Case: No tree
        if(root==nullptr) return;
        
        TreeNode* curr = root;
        while(curr!=nullptr)
        {
            if(key < curr->val)
            {
                suc = curr;
                curr = curr->left;
            }
            else if(key > curr->val)
            {
                pre = curr;
                curr = curr->right;
            }
            else
            {
                TreeNode *temp = curr;
                // Successor
                if(curr->right)
                {
                    // Get the leftmost child from this right subtree
                    curr = curr->right;
                    while(curr->left) curr = curr->left;
                    suc = curr;
                }

                // Predecessor
                if(temp->left)
                {
                    // Get the rightmost child from this left subtree
                    temp = temp->left;
                    while(temp->right) temp = temp->right;
                    pre = temp;
                }
                return;
            }
        }
    }
};

int main()
{
    // root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 8
    // Build the tree
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    // Inorder traversal produces this
    // 4 8 10 12 14 20 22

    Solution obj;
    TreeNode * pre = nullptr, *suc = nullptr;
    obj.findPreSuc(root, pre, suc, 8);
    if(pre!=nullptr)    cout<<"Predecessor: "<<pre->val<<endl;
    else    cout<<"Predecessor: -1"<<endl;
    if(suc!=nullptr)    cout<<"Successor: "<<suc->val<<endl;
    else    cout<<"Successor: -1"<<endl;

    return 0;
}

// OUTPUT:
// Predecessor: 4
// Successor: 10






