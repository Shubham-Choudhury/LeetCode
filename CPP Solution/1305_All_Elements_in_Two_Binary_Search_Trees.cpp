// Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

#include <bits/stdc++.h>
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> s1, s2;
        TreeNode* node1 = root1, *node2 = root2;
        while (node1 || !s1.empty() || node2 || !s2.empty()) {
            while (node1) {
                s1.push(node1);
                node1 = node1->left;
            }
            while (node2) {
                s2.push(node2);
                node2 = node2->left;
            }
            if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
                node1 = s1.top();
                s1.pop();
                ans.push_back(node1->val);
                node1 = node1->right;
            } else {
                node2 = s2.top();
                s2.pop();
                ans.push_back(node2->val);
                node2 = node2->right;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);
    vector<int> ans = sol.getAllElements(root1, root2);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
