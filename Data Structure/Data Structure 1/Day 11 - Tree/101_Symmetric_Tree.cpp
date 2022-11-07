// Link: https://leetcode.com/problems/symmetric-tree/?envType=study-plan&id=data-structure-i

#include <iostream>
#include <vector>
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


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        if (left->val != right->val)
            return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
};

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << sol.isSymmetric(root) << endl;
    return 0;
}