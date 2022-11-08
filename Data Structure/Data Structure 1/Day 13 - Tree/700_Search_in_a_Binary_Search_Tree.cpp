// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/?envType=study-plan&id=data-structure-i

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val = 2;
    TreeNode* ans = sol.searchBST(root, val);
    cout << ans->val << endl;
    return 0;
}