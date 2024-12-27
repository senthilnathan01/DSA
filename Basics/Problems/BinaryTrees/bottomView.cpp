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
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.
*/

vector<int> bottomView(TreeNode *root) {
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

    vector<int> result = bottomView(root);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}

// OUTPUT:
// 4 2 6 3 7  


