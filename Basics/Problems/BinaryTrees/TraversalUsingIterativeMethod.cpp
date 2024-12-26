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

// Root -> Left -> Right
vector<int> iterativePreorderTraversal(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr)
    {
        return result;
    }

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode* current = s.top();
        s.pop();
        result.push_back(current->val);

        if (current->right != nullptr)
        {
            s.push(current->right);
        }

        if (current->left != nullptr)
        {
            s.push(current->left);
        }
    }

    return result;
}

// Left -> Root -> Right
vector<int> iterativeInorderTraversal(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr)
    {
        return result;
    }

    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}

// Left -> Right -> Root
vector<int> iterativePostorderTraversal(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr)
    {
        return result;
    }

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode* current = s.top();
        s.pop();
        result.insert(result.begin(), current->val);

        if (current->left != nullptr)
        {
            s.push(current->left);
        }

        if (current->right != nullptr)
        {
            s.push(current->right);
        }
    }

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

    vector<int> preorder = iterativePreorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;

    vector<int> inorder = iterativeInorderTraversal(root);
    cout << "Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;

    vector<int> postorder = iterativePostorderTraversal(root);
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
