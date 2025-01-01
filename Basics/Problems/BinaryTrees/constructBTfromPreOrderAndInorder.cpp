#include<iostream>
#include<vector>
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

class Solution
{
    public:
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder)
    {
        map<int, int> inMap;
        for(int i = 0; i <inOrder.size(); i++)
        {
            inMap[inOrder[i]]=i;
        }

        TreeNode* root = helper(preOrder, 0, preOrder.size()-1,  inOrder, 0, inOrder.size()-1, inMap);

        return root;
    }
    TreeNode* helper(vector<int>& preOrder, int preStart, int preEnd,
                    vector<int>& inOrder, int inStart, int inEnd, map<int,int>& inMap)
    {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preOrder[preStart]);
         
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = helper(preOrder, preStart + 1, preStart + numsLeft,
                    inOrder, inStart, inRoot -1, inMap);

        root->right = helper(preOrder, preStart+numsLeft+1, preEnd,
                    inOrder, inRoot+1, inEnd, inMap);

        return root;               
    }
};

int main()
{
    vector<int> preOrder = {3,9,20,15,7};
    vector<int> inOrder = {9,3,15,20,7};
    Solution obj;
    TreeNode* root = obj.buildTree(preOrder, inOrder);

    // Display the tree
    cout << "Root: " << root->val << endl;
    cout << "Root->left: " << root->left->val << endl;
    cout << "Root->right: " << root->right->val << endl;
    cout << "Root->right->left: " << root->right->left->val << endl;
    cout << "Root->right->right: " << root->right->right->val << endl;
    
    return 0;
}

// Output:
// Root: 3
// Root->left: 9
// Root->right: 20
// Root->right->left: 15
// Root->right->right: 7