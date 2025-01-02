#include<iostream>
#include<stack>
#include<vector>

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
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
*/
class BSTIterator {
    stack<TreeNode*> myStack;
    // reverse = true --> before
    // reverse = false --> next
    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool isReverse) 
    {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode *temp = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
private:
    void pushAll(TreeNode* node)
    {
        while(node!=NULL)
        {
            myStack.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
};

class Solution
{
public:
    // TC = O(n)
    // SC = O(n)
    bool findTarget0(TreeNode* root, int k) {
        // Do an inorder traversal of the tree and store the numbers in an array
        // Inorder traversal is always sorted
        // Perform twoSum for this array using two pointers
        vector<int> inOrder;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr != nullptr || !s.empty())
        {
            while(curr!=nullptr)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            inOrder.push_back(curr->val);
            curr = curr->right;
        }

        int left = 0, right = inOrder.size()-1;
        while(left<right)
        {
            int sum = inOrder[left] + inOrder[right];
            if(sum<k) left++;
            else if(sum> k) right--;
            else return true;
        }
        return false;
    }

    // Improved SC
    // TC = O(n)
    // SC = O(2*H)
    bool findTarget(TreeNode* root, int k)
    {
        if(root==nullptr) return false;
        
        // next
        BSTIterator l(root, false);
        // before
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next(); //r.before();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j = r.next();
        }
        return false;
    }
};

int main()
{
    // root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 8
    // Build the tree
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    Solution obj;
    cout<<obj.findTarget(root, 28);

    return 0;
}

// OUTPUT:
// 1






