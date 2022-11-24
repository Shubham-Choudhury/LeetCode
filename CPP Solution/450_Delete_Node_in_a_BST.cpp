// Link: https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL)
                return NULL;
            if (root->left == NULL)
                return root->right;
            if (root->right == NULL)
                return root->left;
            TreeNode* node = root->right;
            while (node->left != NULL)
                node = node->left;
            root->val = node->val;
            root->right = deleteNode(root->right, node->val);
        } else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    root = s.deleteNode(root, 3);
    return 0;
}