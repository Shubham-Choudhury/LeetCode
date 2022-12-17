// Link: https://leetcode.com/problems/binary-tree-cameras/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        if (dfs(root, res) == 0) {
            res++;
        }
        return res;
    }
    
    int dfs(TreeNode* root, int& res) {
        if (root == nullptr) {
            return 1;
        }
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        if (left == 0 || right == 0) {
            res++;
            return 2;
        }
        if (left == 2 || right == 2) {
            return 1;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    cout << sol.minCameraCover(root) << endl;
    return 0;
}
