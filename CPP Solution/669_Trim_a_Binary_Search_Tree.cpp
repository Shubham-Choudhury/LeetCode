// Link: https://leetcode.com/problems/trim-a-binary-search-tree/

#include <iostream>
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root)
        {
            return nullptr;
        }
        if (root->val < low)
        {
            return trimBST(root->right, low, high);
        }
        if (root->val > high)
        {
            return trimBST(root->left, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

int main(void)
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    TreeNode *res = sol.trimBST(root, 1, 2);
    return 0;
}
