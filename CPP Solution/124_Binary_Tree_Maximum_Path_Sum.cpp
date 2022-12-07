// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <iostream>
#include <vector>
#include <string>
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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
    int maxPathSum(TreeNode* root, int& res){
        if(!root) return 0;
        int left = max(0, maxPathSum(root->left, res));
        int right = max(0, maxPathSum(root->right, res));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int result = solution.maxPathSum(root);
    cout << result << endl;
    
    return 0;
}