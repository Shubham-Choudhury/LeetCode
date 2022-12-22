// Link: https://leetcode.com/problems/longest-univalue-path/

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
    int longestUnivaluePath(TreeNode *root)
    {
        int res = 0;
        helper(root, res);
        return res;
    }

private:
    int helper(TreeNode *root, int &res)
    {
        if (!root)
            return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        int arrowLeft = 0, arrowRight = 0;
        if (root->left && root->left->val == root->val)
            arrowLeft += left + 1;
        if (root->right && root->right->val == root->val)
            arrowRight += right + 1;
        res = max(res, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
};

int main()
{
    Solution obj;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(5);
    cout << obj.longestUnivaluePath(root) << endl;
    return 0;
}
