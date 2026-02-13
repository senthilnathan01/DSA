/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

LINK: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/?envType=problem-list-v2&envId=7p5x763
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // we want to go up from target too -> so let's convert this to undirected graph
        // let's do bfs to find
        
        // construct undirected graph
        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            } 
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            } 
        }

        // do BFS
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> bfs;

        bfs.push(target);
        int distance = 0;
        visited.insert(target);
        
        while(!bfs.empty()){
            int size = bfs.size();
            if(distance == k){
                vector<int> ans;
                while(!bfs.empty()){
                    ans.push_back(bfs.front()->val);
                    bfs.pop();
                }
                return ans;
            }

            for(int i = 0; i < size; i++){
                TreeNode* curr = bfs.front();
                bfs.pop();

                // explore left
                if(curr->left && !visited.count(curr->left)){
                    visited.insert(curr->left);
                    bfs.push(curr->left);
                }

                //explore right
                if(curr->right && !visited.count(curr->right)){
                    visited.insert(curr->right);
                    bfs.push(curr->right);
                }

                //explore parent
                if(parent.count(curr) && !visited.count(parent[curr])){
                    visited.insert(parent[curr]);
                    bfs.push(parent[curr]);
                }  
            }
            distance++;
        }

        return {};
    }
};
