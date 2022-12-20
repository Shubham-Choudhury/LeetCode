// Link: https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int maxIndex = left;
        for (int i = left; i <= right; ++i)
        {
            if (nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = helper(nums, left, maxIndex - 1);
        root->right = helper(nums, maxIndex + 1, right);
        return root;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *root = sol.constructMaximumBinaryTree(nums);
    return 0;
}
