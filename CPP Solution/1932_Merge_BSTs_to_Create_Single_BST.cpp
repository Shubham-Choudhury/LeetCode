// Link: https://leetcode.com/problems/merge-bsts-to-create-single-bst/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode *canMerge(vector<TreeNode *> &trees)
    {
        unordered_map<int, TreeNode **> qs;
        int total = 1;
        for (TreeNode *t : trees)
        {
            if (t->left)
                qs[t->left->val] = &t->left, ++total;
            if (t->right)
                qs[t->right->val] = &t->right, ++total;
        }
        TreeNode *root = nullptr;
        for (TreeNode *t : trees)
        {
            if (qs.count(t->val))
                *qs[t->val] = t;
            else if (!root)
                root = t;
            else
                return nullptr;
        }
        if (count(root) != total)
            return nullptr;
        if (check(root, numeric_limits<int>::min(), numeric_limits<int>::max()))
            return root;
        return nullptr;
    }

    bool check(TreeNode *t, int mini, int maxi)
    {
        if (!t)
            return true;
        if (t->val <= mini || t->val >= maxi)
            return false;
        return check(t->left, mini, t->val) && check(t->right, t->val, maxi);
    }

    int count(TreeNode *t)
    {
        if (!t)
            return 0;
        return 1 + count(t->left) + count(t->right);
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<TreeNode *> trees;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    trees.push_back(root);
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    trees.push_back(root);
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    trees.push_back(root);
    root = sol->canMerge(trees);
    return 0;
}
