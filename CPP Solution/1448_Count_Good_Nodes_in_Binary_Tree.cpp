// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

#include <iostream>
using namespace std;

#define INT_MIN -2147483648

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
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
    
    int goodNodes(TreeNode* root, int max) {
        if (root == nullptr) return 0;
        int count = 0;
        if (root->val >= max) {
            count++;
            max = root->val;
        }
        return count + goodNodes(root->left, max) + goodNodes(root->right, max);
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    cout << s.goodNodes(root) << endl;
    return 0;
}