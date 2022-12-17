// Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    TreeNode *recoverFromPreorder(string S)
    {
        int n = S.size();
        vector<TreeNode *> stack;
        int i = 0;
        while (i < n)
        {
            int level = 0;
            while (S[i] == '-')
            {
                ++level;
                ++i;
            }
            int val = 0;
            while (i < n && isdigit(S[i]))
            {
                val = val * 10 + (S[i] - '0');
                ++i;
            }
            TreeNode *node = new TreeNode(val);
            if (level == stack.size())
            {
                if (!stack.empty())
                {
                    stack.back()->left = node;
                }
            }
            else
            {
                stack.resize(level);
                stack.back()->right = node;
            }
            stack.push_back(node);
        }
        return stack[0];
    }
};

int main()
{
    Solution sol;
    string S = "1-2--3--4-5--6--7";
    TreeNode *root = sol.recoverFromPreorder(S);
    return 0;
}
