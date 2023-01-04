// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int index = 0;
        return bstFromPreorder(preorder, index, INT_MIN, INT_MAX);
    }

    TreeNode *bstFromPreorder(vector<int> &preorder, int &index, int min, int max)
    {
        if (index == preorder.size())
            return NULL;
        int val = preorder[index];
        if (val < min || val > max)
            return NULL;
        TreeNode *root = new TreeNode(val);
        index++;
        root->left = bstFromPreorder(preorder, index, min, val);
        root->right = bstFromPreorder(preorder, index, val, max);
        return root;
    }
};

int main()
{
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode *root = sol.bstFromPreorder(preorder);
    return 0;
}
