// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/?envType=study-plan&id=data-structure-ii

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = 0;
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == preorder[preStart]) {
                inIndex = i;
                break;
            }
        }
        int leftSize = inIndex - inStart;
        root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftSize, inStart, inIndex - 1);
        root->right = buildTree(preorder, inorder, preStart + leftSize + 1, preEnd, inIndex + 1, inEnd);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = s.buildTree(preorder, inorder);
    return 0;
}