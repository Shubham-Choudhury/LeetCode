// Link: https://leetcode.com/problems/balance-a-binary-search-tree/

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
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return build(v, 0, v.size() - 1);
    }
    TreeNode* build(vector<int>& v, int l, int r) {
        if (l > r) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = build(v, l, mid - 1);
        root->right = build(v, mid + 1, r);
        return root;
    }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution s;
    TreeNode* ans = s.balanceBST(root);
    return 0;
}