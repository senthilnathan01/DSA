#include<iostream>
#include<vector>
#include<stack>

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

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> preorder, inorder, postorder;
    stack<pair<TreeNode*, int>> s;
    s.push({root, 1});

    while (!s.empty())
    {
        auto it = s.top();
        s.pop();

        if (it.second == 1)
        {
            preorder.push_back(it.first->val);
            it.second++;
            s.push(it);

            if (it.first->left != nullptr)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->val);
            it.second++;
            s.push(it);

            if (it.first->right != nullptr)
            {
                s.push({it.first->right, 1});
            }
        }
        else
        {
            postorder.push_back(it.first->val);
        }
    }

    cout << "Preorder Traversal: ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;

    cout << "Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;

    cout << "Postorder Traversal: ";
    for (int i = 0; i < postorder.size(); i++)
    {
        cout << postorder[i] << " ";
    }
    cout << endl;

    return 0;
}

// OUTPUT:
// Preorder Traversal: 1 2 4 5 3 6 7 
// Inorder Traversal: 4 2 5 1 6 3 7 
// Postorder Traversal: 4 5 2 6 7 3 1 
