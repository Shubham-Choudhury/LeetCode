// Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        int depth = 0;
        return dfs(root, depth);
    }

    TreeNode *dfs(TreeNode *root, int &depth)
    {
        if (!root)
        {
            depth = 0;
            return NULL;
        }
        int left = 0, right = 0;
        TreeNode *l = dfs(root->left, left);
        TreeNode *r = dfs(root->right, right);
        if (left == right)
        {
            depth = left + 1;
            return root;
        }
        else if (left > right)
        {
            depth = left + 1;
            return l;
        }
        else
        {
            depth = right + 1;
            return r;
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *ans = s.subtreeWithAllDeepest(root);
    cout << ans->val << endl;
    return 0;
}
