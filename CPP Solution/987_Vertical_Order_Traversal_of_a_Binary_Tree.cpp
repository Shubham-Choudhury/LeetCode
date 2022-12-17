// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        map<int, vector<int>> m;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            map<int, vector<int>> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front().first;
                int col = q.front().second;
                q.pop();
                temp[col].push_back(node->val);
                if (node->left != nullptr)
                {
                    q.push({node->left, col - 1});
                }
                if (node->right != nullptr)
                {
                    q.push({node->right, col + 1});
                }
            }
            for (auto it = temp.begin(); it != temp.end(); it++)
            {
                sort(it->second.begin(), it->second.end());
                m[it->first].insert(m[it->first].end(), it->second.begin(), it->second.end());
            }
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = sol.verticalTraversal(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}