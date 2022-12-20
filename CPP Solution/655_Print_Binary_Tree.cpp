// Link: https://leetcode.com/problems/print-binary-tree/

#include <iostream>
#include <vector>
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
    vector<vector<string>> printTree(TreeNode *root)
    {
        int height = getHeight(root);
        int width = (1 << height) - 1;
        vector<vector<string>> res(height, vector<string>(width, ""));
        helper(root, res, 0, 0, width - 1);
        return res;
    }

    void helper(TreeNode *root, vector<vector<string>> &res, int level, int left, int right)
    {
        if (!root)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        res[level][mid] = to_string(root->val);
        helper(root->left, res, level + 1, left, mid - 1);
        helper(root->right, res, level + 1, mid + 1, right);
    }

    int getHeight(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};

int main(void)
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    vector<vector<string>> res = sol.printTree(root);
    for (auto row : res)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}
