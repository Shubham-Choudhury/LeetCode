// Link: https://leetcode.com/problems/binary-tree-paths/

#include <iostream>
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL) {
            return result;
        }
        if (root->left == NULL && root->right == NULL) {
            result.push_back(to_string(root->val));
            return result;
        }
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        for (int i = 0; i < left.size(); i++) {
            result.push_back(to_string(root->val) + "->" + left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            result.push_back(to_string(root->val) + "->" + right[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    vector<string> result = s.binaryTreePaths(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}