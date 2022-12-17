// Link: https://leetcode.com/problems/house-robber-iii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
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
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> memo;
        return rob(root, memo);
    }

private:
    int rob(TreeNode *root, unordered_map<TreeNode *, int> &memo)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (memo.count(root))
        {
            return memo[root];
        }
        int val = 0;
        if (root->left != nullptr)
        {
            val += rob(root->left->left, memo) + rob(root->left->right, memo);
        }
        if (root->right != nullptr)
        {
            val += rob(root->right->left, memo) + rob(root->right->right, memo);
        }
        val = max(val + root->val, rob(root->left, memo) + rob(root->right, memo));
        memo[root] = val;
        return val;
    }
};

int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(3, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(3, nullptr, new TreeNode(1)));
    cout << solution.rob(root) << endl;
    return 0;
}