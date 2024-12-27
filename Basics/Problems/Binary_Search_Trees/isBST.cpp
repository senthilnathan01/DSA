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
Given an array of integers arr[] representing inorder traversal of elements of a binary tree. 
Return true if the given inorder traversal can be of a valid Binary Search Tree.
*/

bool isBSTTraversal(vector<int>& arr) {
    for(int i = 1; i<arr.size(); i++)
    {
        if(arr[i]<=arr[i-1]) return false;
    }
    return true;
}

int main()
{
    vector<int> arr = {8, 14, 45, 64, 100};
    cout << isBSTTraversal(arr) << endl;
    return 0;
}

// OUTPUT:
// 1



