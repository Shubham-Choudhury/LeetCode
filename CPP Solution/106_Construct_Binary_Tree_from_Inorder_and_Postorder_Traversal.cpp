// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        if (n == 0)
            return nullptr;
        return buildTree(inorder, 0, n - 1, postorder, 0, n - 1);
    }

    TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;
        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);
        int rootIndex = 0;
        for (int i = inStart; i <= inEnd; ++i)
        {
            if (inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }
        int leftSize = rootIndex - inStart;
        root->left = buildTree(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSize - 1);
        root->right = buildTree(inorder, rootIndex + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = s.buildTree(inorder, postorder);
    return 0;
}

