// Link: https://leetcode.com/problems/sum-of-left-leaves/?envType=study-plan&id=programming-skills-i

#include <iostream>
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            sum += root->left->val;
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sol.sumOfLeftLeaves(root) << endl;
    return 0;
}