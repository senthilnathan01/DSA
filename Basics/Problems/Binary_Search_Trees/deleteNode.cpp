#include<iostream>
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
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
*/

class Solution
{
public:
    
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == key)
        {
            if (root->left == nullptr)
            {
                return root->right;
            }
            if (root->right == nullptr)
            {
                return root->left;
            }

            TreeNode* minNode = findMin(root->right); 
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

    TreeNode* findMin(TreeNode* root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }

        return root;
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

    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout<<endl;

    Solution obj;
    TreeNode* result = obj.deleteNode(root, 12);

    // Print the inorder traversal of the modified tree
    curr = result;
    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
    return 0;
}

// OUTPUT:
// 2 4 6 8 10 12 14 
// 2 4 6 8 10 14 



