// Link: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

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
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val < limit)
                return NULL;
            return root;
        }
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);
        if (root->left == NULL && root->right == NULL)
            return NULL;
        return root;
    }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(-99);
    root->right->left = new TreeNode(-99);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->left->left->left = new TreeNode(10);
    root->left->left->left->right = new TreeNode(11);
    int limit = 1;
    TreeNode *res = sol.sufficientSubset(root, limit);
    return 0;
}