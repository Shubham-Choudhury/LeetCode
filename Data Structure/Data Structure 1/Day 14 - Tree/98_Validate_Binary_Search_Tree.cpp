// Link: https://leetcode.com/problems/validate-binary-search-tree/?envType=study-plan&id=data-structure-i

#include <iostream>
#include <vector>
#include <stack>
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long min, long max) {
        if (root == NULL) return true;
        if (root->val <= min || root->val >= max) return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << s.isValidBST(root) << endl;
    return 0;
}