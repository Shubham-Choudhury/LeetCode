// Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

#include <bits/stdc++.h>
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
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL) return NULL;
        int left = depth(root->left);
        int right = depth(root->right);
        if (left == right) return root;
        if (left > right) return lcaDeepestLeaves(root->left);
        return lcaDeepestLeaves(root->right);
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);
    root->left->left->left->left = new TreeNode(16);
    root->left->left->left->right = new TreeNode(17);
    root->left->left->right->left = new TreeNode(18);
    root->left->left->right->right = new TreeNode(19);
    root->left->right->left->left = new TreeNode(20);
    root->left->right->left->right = new TreeNode(21);
    root->left->right->right->left = new TreeNode(22);
    root->left->right->right->right = new TreeNode(23);
    root->right->left->left->left = new TreeNode(24);
    root->right->left->left->right = new TreeNode(25);
    root->right->left->right->left = new TreeNode(26);

    TreeNode* ans = s.lcaDeepestLeaves(root);
    cout << ans->val << endl;
    return 0;
}

    