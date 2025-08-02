/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

LeetCode Link: https://leetcode.com/problems/binary-tree-right-side-view/description/
*/

// Solution 1:
// Do a level order Traversal
// return a list with only the last element from each level

// Solution 2:
// Similar to the one above
// With better space complexity
// We have a map (line, element)
// We update the map with the last element in that line
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0}); 
        while(!q.empty())
        {
            TreeNode* temp = q.front().first;
            int line = q.front().second;
            q.pop();

            mpp[line] = temp->val;

            // Observe the order
            // We do left and then right
            // If we do in opposite we get the left side view
            if(temp->left) q.push({temp->left, line + 1});
            if(temp->right) q.push({temp->right, line + 1});
        }

        for(auto p: mpp) ans.push_back(p.second);
        return ans;
    }
};
