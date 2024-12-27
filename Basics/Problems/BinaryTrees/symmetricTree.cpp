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
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/


bool isSymmetric(TreeNode* root)
{
    if (root == nullptr)
        return true;

    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty())
    {
        TreeNode* leftNode = q.front();
        q.pop();
        TreeNode* rightNode = q.front();
        q.pop();

        if (leftNode == nullptr && rightNode == nullptr)
            continue;

        if (leftNode == nullptr || rightNode == nullptr)
            return false;

        if (leftNode->val != rightNode->val)
            return false;

        q.push(leftNode->left);
        q.push(rightNode->right);
        q.push(leftNode->right);
        q.push(rightNode->left);
    }

    return true;
}


int main()
{
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    cout << isSymmetric(root1) << endl;

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);

    cout << isSymmetric(root2) << endl;

}

// OUTPUT:
// 0
// 1


