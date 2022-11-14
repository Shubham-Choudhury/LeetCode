// Link: https://leetcode.com/problems/diameter-of-binary-tree/?envType=study-plan&id=level-2

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
    
    int depth(TreeNode* root, int& diameter) {
        if (root == NULL) {
            return 0;
        }
        int left = depth(root->left, diameter);
        int right = depth(root->right, diameter);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << s.diameterOfBinaryTree(root) << endl;
    return 0;
}