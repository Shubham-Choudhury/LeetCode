// Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    // ans={sum,min,max,min_height,max_height,BST}
    int result = 0;
    vector<int> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, INT_MAX, INT_MIN, 0, 0, 1};
        }

        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);

        if (l.back() == 1 && r.back() == 1)
        {

            if ((l[2] < r[1]) && (root->val > l[2]) && (root->val < r[1]))
            {

                vector<int> temp = {l[0] + r[0] + (root->val), min(l[1], root->val), max(root->val, r[2]), min(l[3], r[3]) + 1, max(l[4], r[4]) + 1, 1};
                result = max(result, temp[0]);
                return temp;
            }
            else
            {
                return {0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 0, 0, 0};
            }
        }
        else
        {
            return {0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 0, 0, 0};
        }
    }

    int maxSumBST(TreeNode *root)
    {

        vector<int> ans = solve(root);

        return result;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    cout << s.maxSumBST(root) << endl;
    return 0;
}
