// Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->val % 2 == 0) {
                    if (node->left) {
                        if (node->left->left) ans += node->left->left->val;
                        if (node->left->right) ans += node->left->right->val;
                    }
                    if (node->right) {
                        if (node->right->left) ans += node->right->left->val;
                        if (node->right->right) ans += node->right->right->val;
                    }
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(9);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    cout << sol.sumEvenGrandparent(root) << endl;
    return 0;
}
