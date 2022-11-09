// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/?envType=study-plan&id=data-structure-i

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        stack<TreeNode*> s;
        s.push(root);
        unordered_set<int> set;
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (set.find(k - node->val) != set.end()) return true;
            set.insert(node->val);
            if (node->left != NULL) s.push(node->left);
            if (node->right != NULL) s.push(node->right);
        }
        return false;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    cout << s.findTarget(root, 9) << endl;
    return 0;
}