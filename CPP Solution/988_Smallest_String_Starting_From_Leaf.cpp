// Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string answer = "~";

public:
    void recure(TreeNode *root, string s)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            answer = min(answer, char(root->val + 'a') + s);
        }
        recure(root->left, char(root->val + 'a') + s);
        recure(root->right, char(root->val + 'a') + s);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        recure(root, "");
        return answer;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    cout << sol.smallestFromLeaf(root) << endl;
    return 0;
}
