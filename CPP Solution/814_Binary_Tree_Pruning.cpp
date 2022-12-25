// Link: https://leetcode.com/problems/binary-tree-pruning/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left == NULL && root->right == NULL && root->val == 0)
        {
            return NULL;
        }
        return root;
    }
};

int main()
{
    Solution s;
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    s.pruneTree(root);
    return 0;
}
