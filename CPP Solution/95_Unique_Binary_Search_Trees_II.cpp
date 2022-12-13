// Link: https://leetcode.com/problems/unique-binary-search-trees-ii/

#include <iostream>
#include <vector>
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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end)
    {
        vector<TreeNode *> res;
        if (start > end)
        {
            res.push_back(nullptr);
            return res;
        }
        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode *> left = generateTrees(start, i - 1);
            vector<TreeNode *> right = generateTrees(i + 1, end);
            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<TreeNode *> res = s.generateTrees(3);
    for (auto i : res)
        cout << i << endl;
    return 0;
}
