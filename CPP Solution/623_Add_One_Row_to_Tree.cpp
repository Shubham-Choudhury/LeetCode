// Link: https://leetcode.com/problems/add-one-row-to-tree/

#include <iostream>
#include <queue>
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
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        if (d == 1)
        {
            TreeNode *new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (depth == d - 1)
                {
                    TreeNode *left = node->left;
                    TreeNode *right = node->right;
                    node->left = new TreeNode(v);
                    node->right = new TreeNode(v);
                    node->left->left = left;
                    node->right->right = right;
                }
                else
                {
                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
            }
            depth++;
        }
        return root;
    }
};

int main(void)
{
    Solution sol;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);
    int v = 1;
    int d = 2;
    TreeNode *res = sol.addOneRow(root, v, d);
    return 0;
}
