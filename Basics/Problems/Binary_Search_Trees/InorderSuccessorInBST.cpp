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
Given a BST, and a reference to a Node k in the BST. 
Find the Inorder Successor of the given node in the BST. If there is no successor, return -1. 
*/

class Solution
{
public:
    // Do a inorder traversal and get the node that comes after x
    // TC = O(N)
    // But this approach finds all the nodes in the inorder traversal till it reaches the target
    int inOrderSuccessor0(TreeNode *root, TreeNode *x) 
    {
        if(root==nullptr) return -1;

        int target = x->val;
        stack<TreeNode*> s;

        TreeNode* curr = root;
        bool ans = false;

        while(curr!=nullptr || !s.empty())
        {
            while(curr != nullptr)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            if(ans==true) return curr->val;
            if(curr->val == target)
            {
                ans = true;
            }
            curr = curr->right;
        }
        return -1;
    }

    // Better approach would be to get to target as fast as possible
    int inOrderSuccessor(TreeNode *root, TreeNode *x) 
    {
        // Base Case 1: No tree
        if(root==nullptr) return -1;
        
        int target = x->val;
        // Base Case 2: Root = x
        if(root->val == target && root->right != nullptr)
        {
            // Get the leftmost in the right subtree after root
            TreeNode* curr=root->right;
            while(curr->left) curr = curr->left;
            return curr->val;
        }

        // Search for target and successor
        TreeNode* successor = nullptr;
        TreeNode* curr = root;
        while(curr != nullptr)
        {
            if(target < curr->val)
            {
                successor = curr;
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if(successor == nullptr) return -1;
        else return successor->val;
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

    Solution obj;
    cout<<obj.inOrderSuccessor(root, root->left)<<endl;

    return 0;
}

// OUTPUT:
// 10





