// Link: https://leetcode.com/problems/delete-nodes-and-return-forest/

#include <bits/stdc++.h>
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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        dfs(root, to_delete_set, ans, true);
        return ans;
    }

    TreeNode *dfs(TreeNode *root, unordered_set<int> &to_delete_set, vector<TreeNode *> &ans, bool is_root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        bool deleted = to_delete_set.find(root->val) != to_delete_set.end();
        if (is_root && !deleted)
        {
            ans.push_back(root);
        }
        root->left = dfs(root->left, to_delete_set, ans, deleted);
        root->right = dfs(root->right, to_delete_set, ans, deleted);
        return deleted ? nullptr : root;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    vector<int> to_delete = {3, 5};
    vector<TreeNode *> ans = sol.delNodes(root, to_delete);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]->val << " ";
    }
    cout << endl;
    return 0;
}
