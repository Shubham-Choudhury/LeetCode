// Link: https://leetcode.com/problems/recover-binary-search-tree/

#include <iostream>
#include <vector>
#include <stack>
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
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        stack<TreeNode *> s;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (prev && prev->val > root->val)
            {
                if (!first)
                    first = prev;
                second = root;
            }
            prev = root;
            root = root->right;
        }
        swap(first->val, second->val);
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    s.recoverTree(root);
    return 0;
}

