// Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int maxVal = INT_MIN;
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            result.push_back(maxVal);
        }
        return result;
    }
};

int main()
{
    Solution s;
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    vector<int> res = s.largestValues(root);
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
