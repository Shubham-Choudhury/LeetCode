// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0) {
            return right + 1;
        }
        if (right == 0) {
            return left + 1;
        }
        return min(left, right) + 1;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int result = s.minDepth(root);
    cout << result << endl;
    return 0;
}