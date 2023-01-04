// Link: https://leetcode.com/problems/maximum-binary-tree-ii/

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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root == NULL || root->val < val)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    int val = 5;
    TreeNode *ans = sol.insertIntoMaxTree(root, val);
    return 0;
}
