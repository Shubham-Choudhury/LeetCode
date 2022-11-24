// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>  
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* result = s.sortedArrayToBST(nums);
    return 0;
}
