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
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;

    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode* temp = it.first;
        int line = it.second;

        mpp[line]=temp->val;
        if(temp->left) q.push({temp->left, line+1});
        if(temp->right) q.push({temp->right, line+1}); 
    }
    for(auto i: mpp)
    {
        ans.push_back(i.second);
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

    vector<int> result = rightSideView(root);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}

// OUTPUT:
// 1 3 7


