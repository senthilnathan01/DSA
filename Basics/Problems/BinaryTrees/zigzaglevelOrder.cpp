#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
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
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
*/

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    if (root == nullptr)
    {
        return result;
    }

    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;
    currentLevel.push(root);
    bool leftToRight = true;
    vector<int> levelNodes;

    while (!currentLevel.empty())
    {
        TreeNode* node = currentLevel.top();
        currentLevel.pop();
        levelNodes.push_back(node->val);

        if (leftToRight)
        {
            if (node->left != nullptr)
            {
                nextLevel.push(node->left);
            }
            if (node->right != nullptr)
            {
                nextLevel.push(node->right);
            }
        }
        else
        {
            if (node->right != nullptr)
            {
                nextLevel.push(node->right);
            }
            if (node->left != nullptr)
            {
                nextLevel.push(node->left);
            }
        }

        if (currentLevel.empty())
        {
            result.push_back(levelNodes);
            levelNodes.clear();
            swap(currentLevel, nextLevel);
            leftToRight = !leftToRight;
        }
    }

    return result;
}

// Alternative solution using queue
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    if(root == NULL)
    {
        return result;
    }
    bool leftToRight = true;
    vector<int> level;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        if(node != NULL)
        {
            level.push_back(node->val);
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else
        {
            if(leftToRight == false)
            {
                reverse(level.begin(), level.end());
            }
            result.push_back(level);
            leftToRight = !leftToRight;
            level.clear();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
    }
    return result;
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

    vector<vector<int>> result = zigzagLevelOrder(root);
    for (vector<int> level : result)
    {
        for (int node : level)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result2 = levelOrder(root);
    for (vector<int> level : result2)
    {
        for (int node : level)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

// OUTPUT:
// 1 
// 3 2 
// 4 5 6 7 
// 1 
// 3 2 
// 4 5 6 7 

