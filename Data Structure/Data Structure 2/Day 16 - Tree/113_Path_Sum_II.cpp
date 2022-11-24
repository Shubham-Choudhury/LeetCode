// Link: https://leetcode.com/problems/path-sum-ii/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        pathSum(root, targetSum, path, res);
        return res;
    }
    
    void pathSum(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& res) {
        if(root == NULL)
            return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && targetSum == root->val)
            res.push_back(path);
        pathSum(root->left, targetSum - root->val, path, res);
        pathSum(root->right, targetSum - root->val, path, res);
        path.pop_back();
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    vector<vector<int>> res = s.pathSum(root, 22);
    return 0;
}