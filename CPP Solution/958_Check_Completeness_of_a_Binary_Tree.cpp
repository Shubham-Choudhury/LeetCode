// Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == NULL)
            {
                flag = true;
            }
            else
            {
                if (flag)
                {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
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
    root->right->left = new TreeNode(6);
    cout << sol.isCompleteTree(root) << endl;
    return 0;
}
