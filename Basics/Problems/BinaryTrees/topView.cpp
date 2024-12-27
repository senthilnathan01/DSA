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
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
*/

vector<int> topView(TreeNode *root) {
    vector<int> result;
    if(root == NULL)
        return result;
    
    map<int, int> m;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int hd = it.second;
        
        if(m.find(hd) == m.end())
            m[hd] = node->val;
        
        if(node->left)
            q.push({node->left, hd-1});
        if(node->right)
            q.push({node->right, hd+1});
    }
    
    for(auto i: m)
        result.push_back(i.second);
    
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

    vector<int> result = topView(root);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}

// OUTPUT:
// 4 2 1 3 7 


