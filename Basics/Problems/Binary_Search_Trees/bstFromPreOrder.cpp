#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>

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
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/

class Solution
{
public:
    // Naive approach
    // TC = O(N*N) = O(N^2)
    TreeNode* bstFromPreorder0(vector<int>& preorder)
    {
        if(preorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i<preorder.size(); i++)
        {
            TreeNode* temp = root;
            while(true)
            {
                if(preorder[i]<temp->val)
                {
                    if(temp->left) temp = temp->left;
                    else 
                    {
                        temp->left = new TreeNode(preorder[i]);
                        break;
                    }
                }
                else 
                {
                    if(temp->right) temp = temp->right;
                    else 
                    {
                        temp->right = new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
        }
        return root;
    }

    // Construct a unique BST using preorder and inorder traversal
    // TC = O(nlogn+n)
    // SC = O(n) (for the extra vector)
    TreeNode* helper(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd, map<int, int>& inMap)
    {
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode *root = new TreeNode(preOrder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = helper(preOrder, preStart+1, preStart+numsLeft, inOrder, inStart, inRoot-1, inMap);
        root->right = helper(preOrder, preStart+ numsLeft+1, preEnd, inOrder, inRoot+1, inEnd, inMap);

        return root;
    }

    TreeNode* bstFromPreorder1(vector<int>& preOrder) {
        vector<int> inOrder = preOrder;
        sort(inOrder.begin(), inOrder.end());

        map<int, int> inMap;
        for(int i =0; i<inOrder.size(); i++) inMap[inOrder[i]] = i;

        TreeNode* root = helper(preOrder, 0, preOrder.size()-1, inOrder, 0, inOrder.size()-1, inMap);
        return root;
    }

    // TC = O(3n)(worst case) = O(n)
    // SC = O(1)
    TreeNode* build(vector<int>& preorder, int& i, int bound)
    {
        if(i==preorder.size() || preorder[i]>bound) return NULL;
        
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int i = 0;
        return build(preorder, i, INT32_MAX);
    }
};

int main()
{
    vector<int> preOrder = {8,5,1,7,10,12};
    Solution obj;
    TreeNode* root = obj.bstFromPreorder(preOrder);

    // Level order traversal to check the output
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        ans.push_back(temp->val);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}

// OUTPUT:
// 8 5 10 1 7 12 





