#include<iostream>
#include<vector>
#include<queue>
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
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
*/
// Function to collect leaf nodes
void leafNodes(TreeNode* root, vector<int>& ans)
{
    if(root == NULL)
    {
        return;
    }
    leafNodes(root->left, ans);
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->val);
    }
    leafNodes(root->right, ans);
}

// Function to collect boundary traversal nodes
vector<int> boundaryTraversal(TreeNode *root) {
    // Edge cases
    vector<int> ans;    
    if(root == NULL)
    {
        return ans;
    }
    ans.push_back(root->val);
    if(root->left == NULL && root->right == NULL)
    {
        return ans;
    }

    // Left boundary
    TreeNode* temp = root->left;
    while(temp != NULL)
    {
        if(temp->left != NULL || temp->right != NULL)
        {
            ans.push_back(temp->val);
        }
        if(temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    // Leaf nodes
    leafNodes(root, ans);

    // Right boundary
    stack<int> right;
    temp = root->right;
    while(temp != NULL)
    {
        if(temp->left != NULL || temp->right != NULL)
        {
            right.push(temp->val);
        }
        if(temp->right != NULL)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    while(!right.empty())
    {
        ans.push_back(right.top());
        right.pop();
    }


    return ans;
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

    vector<int> ans = boundaryTraversal(root);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }


    return 0;
}

// OUTPUT:


