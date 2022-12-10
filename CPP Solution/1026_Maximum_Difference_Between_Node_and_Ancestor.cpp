// Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

#include <iostream>
#include <algorithm>
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
    int maxAncestorDiff(TreeNode *root)
    {
        int maxDiff = 0;
        if (root == NULL)
            return maxDiff;

        maxDiff = max(maxDiff, maxDiffHelper(root, root->val, root->val));
        return maxDiff;
    }

    int maxDiffHelper(TreeNode *root, int minVal, int maxVal)
    {
        if (root == NULL)
            return 0;

        int maxDiff = max(abs(root->val - minVal), abs(root->val - maxVal));
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        maxDiff = max(maxDiff, maxDiffHelper(root->left, minVal, maxVal));
        maxDiff = max(maxDiff, maxDiffHelper(root->right, minVal, maxVal));

        return maxDiff;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << s.maxAncestorDiff(root) << endl;

    return 0;
}
