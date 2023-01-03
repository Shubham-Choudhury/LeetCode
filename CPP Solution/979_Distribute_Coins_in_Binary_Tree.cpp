// Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
    int distributeCoins(TreeNode *root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode *root, int &res)
    {
        if (!root)
            return 0;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    cout << sol.distributeCoins(root) << endl;
    return 0;
}
