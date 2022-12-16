// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <iostream>
#include <vector>
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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            return;
        if (root->left)
        {
            flatten(root->left);
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *t = root->right;
            while (t->right)
                t = t->right;
            t->right = temp;
        }
        flatten(root->right);
    }
};

int main()
{
    Solution a;
    TreeNode *b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->right = new TreeNode(5);
    b->left->left = new TreeNode(3);
    b->left->right = new TreeNode(4);
    b->right->right = new TreeNode(6);
    a.flatten(b);
    return 0;
}
