// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

#include <bits/stdc++.h>
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
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        int n = pre.size();
        if (n == 0)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[0]);
        if (n == 1)
        {
            return root;
        }
        int i = 0;
        for (; i < n; i++)
        {
            if (post[i] == pre[1])
            {
                break;
            }
        }
        vector<int> preLeft(pre.begin() + 1, pre.begin() + i + 2);
        vector<int> preRight(pre.begin() + i + 2, pre.end());
        vector<int> postLeft(post.begin(), post.begin() + i + 1);
        vector<int> postRight(post.begin() + i + 1, post.end() - 1);
        root->left = constructFromPrePost(preLeft, postLeft);
        root->right = constructFromPrePost(preRight, postRight);
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> post = {4, 5, 2, 6, 7, 3, 1};
    TreeNode *root = s.constructFromPrePost(pre, post);
    return 0;
}
