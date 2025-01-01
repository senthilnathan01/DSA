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
    TreeNode* buildTree(vector<int>& postOrder, vector<int>& inOrder)
    {
        map<int, int> inMap;
        for(int i = 0; i <inOrder.size(); i++)
        {
            inMap[inOrder[i]]=i;
        }

        TreeNode* root = helper(postOrder, 0, postOrder.size()-1,  inOrder, 0, inOrder.size()-1, inMap);

        return root;
    }
    TreeNode* helper(vector<int>& postOrder, int postStart, int postEnd,
                    vector<int>& inOrder, int inStart, int inEnd, map<int,int>& inMap)
    {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postOrder[postEnd]);
         
        int inRoot = inMap[root->val];
        int numsRight = inEnd - inRoot;

        root->right = helper(postOrder, postEnd-numsRight, postEnd-1,
                    inOrder, inRoot+1, inEnd, inMap);

        root->left = helper(postOrder, postStart, postEnd-numsRight-1,
                    inOrder, inStart, inRoot - 1, inMap);

        return root;               
    }
};

int main()
{
    vector<int> postOrder = {9,15,7,20,4};
    vector<int> inOrder = {9,4,15,20,7};
    Solution obj;
    TreeNode* root = obj.buildTree(postOrder, inOrder);

    // Display the tree
    cout << "Root: " << root->val << endl;
    cout << "Root->left: " << root->left->val << endl;
    cout << "Root->right: " << root->right->val << endl;
    cout << "Root->right->left: " << root->right->left->val << endl;
    cout << "Root->right->right: " << root->right->right->val << endl;
    
    return 0;
}

// Output:
// Root: 4
// Root->left: 9
// Root->right: 20
// Root->right->left: 15
// Root->right->right: 7
