// Link: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

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
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        vector<int> res;
        int i = 0;
        dfs(root, voyage, i, res);
        if (i != voyage.size())
            return {-1};
        return res;
    }

    void dfs(TreeNode *root, vector<int> &voyage, int &i, vector<int> &res)
    {
        if (!root)
            return;
        if (root->val != voyage[i++])
        {
            res = {-1};
            return;
        }
        if (root->left && root->left->val != voyage[i])
        {
            res.push_back(root->val);
            dfs(root->right, voyage, i, res);
            dfs(root->left, voyage, i, res);
        }
        else
        {
            dfs(root->left, voyage, i, res);
            dfs(root->right, voyage, i, res);
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    vector<int> voyage = {2, 1};
    vector<int> res = sol.flipMatchVoyage(root, voyage);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
