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
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/

// Few Approaches:
// 1. Inorder Traversal: Traverse the tree in inorder fashion and keep track of the count of nodes visited so far. When the count becomes equal to k, return the value of the current node.
// 2. Iterative Inorder Traversal: Use a stack to simulate the inorder traversal of the tree. Keep track of the count of nodes visited so far. When the count becomes equal to k, return the value of the current node.
// 3. Morris Inorder Traversal: Use Morris Traversal to simulate the inorder traversal of the tree. Keep track of the count of nodes visited so far. When the count becomes equal to k, return the value of the current node.
// 4. Recursive Inorder Traversal: Use a recursive function to perform the inorder traversal of the tree. Keep track of the count of nodes visited so far. When the count becomes equal to k, return the value of the current node.
// 5. Using a Priority Queue: Perform an inorder traversal of the tree and store the values of the nodes in a priority queue. Return the kth smallest value from the priority queue.
// 6. Using a Set: Perform an inorder traversal of the tree and store the values of the nodes in a set. Return the kth smallest value from the set.

class Solution
{

public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        int count = 0;

        while (curr != nullptr || !s.empty())
        {
            while (curr != nullptr)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            count++;

            if (count == k)
            {
                return curr->val;
            }

            curr = curr->right;
        }

        return -1;
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
    cout << obj.kthSmallest(root, 3) << endl;

    return 0;
}

// Note:
// Among other ways to find Kth Largest, one way to find it is using (n-k+1)th smallest element, where n is the total number of elements in the tree.

// OUTPUT:
// 6



