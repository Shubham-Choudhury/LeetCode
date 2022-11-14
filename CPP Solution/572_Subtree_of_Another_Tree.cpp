// Link: https://leetcode.com/problems/subtree-of-another-tree/?envType=study-plan&id=algorithm-ii

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return false;
        }
        if (isSameTree(s, t)) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) {
            return true;
        }
        if (s == NULL || t == NULL) {
            return false;
        }
        if (s->val != t->val) {
            return false;
        }
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};

int main() {
    TreeNode* s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);
    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);
    s->right->right = new TreeNode(0);
    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);
    Solution sol;
    bool result = sol.isSubtree(s, t);
    cout << result << endl;
    return 0;
}