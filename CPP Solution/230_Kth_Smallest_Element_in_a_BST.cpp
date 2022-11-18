// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        while (root) {
            stack.push(root);
            root = root->left;
        }
        while (k > 0) {
            TreeNode* node = stack.top();
            stack.pop();
            k--;
            if (k == 0) {
                return node->val;
            }
            if (node->right) {
                node = node->right;
                while (node) {
                    stack.push(node);
                    node = node->left;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << s.kthSmallest(root, 1) << endl;
    cout << s.kthSmallest(root, 2) << endl;
    cout << s.kthSmallest(root, 3) << endl;
    cout << s.kthSmallest(root, 4) << endl;
    return 0;
}