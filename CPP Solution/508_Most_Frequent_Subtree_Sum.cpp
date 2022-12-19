// Link: https://leetcode.com/problems/most-frequent-subtree-sum/

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        unordered_map<int, int> m;
        int maxCount = 0;
        findFrequentTreeSum(root, m, maxCount);
        for(auto i : m) {
            if(i.second == maxCount) {
                result.push_back(i.first);
            }
        }
        return result;
    }
private:
    int findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& m, int& maxCount) {
        if(root == NULL) return 0;
        int sum = root->val + findFrequentTreeSum(root->left, m, maxCount) + findFrequentTreeSum(root->right, m, maxCount);
        m[sum]++;
        maxCount = max(maxCount, m[sum]);
        return sum;
    }
};

int main()
{
    Solution s;
    struct TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);
    vector<int> res = s.findFrequentTreeSum(root);
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}