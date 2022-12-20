// Link: https://leetcode.com/problems/find-duplicate-subtrees/

#include <iostream>
#include <string>
#include <unordered_map>
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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> res;
        unordered_map<string, int> m;
        helper(root, m, res);
        return res;
    }

    string helper(TreeNode *root, unordered_map<string, int> &m, vector<TreeNode *> &res)
    {
        if (!root)
        {
            return "#";
        }
        string s = to_string(root->val) + "," + helper(root->left, m, res) + "," + helper(root->right, m, res);
        if (m[s] == 1)
        {
            res.push_back(root);
        }
        m[s]++;
        return s;
    }
};

int main(void)
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);
    vector<TreeNode *> res = sol.findDuplicateSubtrees(root);
    for (auto node : res)
    {
        cout << node->val << endl;
    }
    return 0;
}
