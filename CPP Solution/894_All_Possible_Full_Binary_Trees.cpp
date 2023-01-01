// Link: https://leetcode.com/problems/all-possible-full-binary-trees/

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
    vector<TreeNode *> allPossibleFBT(int N)
    {
        if (N % 2 == 0)
            return {};
        if (N == 1)
            return {new TreeNode(0)};
        vector<TreeNode *> ans;
        for (int i = 1; i < N; i += 2)
        {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(N - i - 1);
            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int N = 7;
    vector<TreeNode *> ans = s.allPossibleFBT(N);
    for (auto root : ans)
    {
        cout << root->val << endl;
    }
    return 0;
}
