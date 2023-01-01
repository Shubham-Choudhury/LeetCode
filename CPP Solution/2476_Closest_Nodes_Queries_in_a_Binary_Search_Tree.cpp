// Link: https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/

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
    vector<int> v;
    void printInorder(TreeNode *node)
    {
        if (node == NULL)
            return;
        printInorder(node->left);
        v.push_back(node->val);
        printInorder(node->right);
    }
    vector<int> binarySearch(int x, int low, int high)
    {
        int mini = -1, maxi = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (v[mid] == x)
                return {v[mid], v[mid]};

            if (v[mid] < x)
            {
                low = mid + 1;
                mini = v[mid];
            }
            else
            {
                high = mid - 1;
                maxi = v[mid];
            }
        }

        return {mini, maxi};
    }
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &q)
    {
        printInorder(root);
        vector<vector<int>> ans;
        for (int i = 0; i < q.size(); i++)
        {
            ans.push_back(binarySearch(q[i], 0, v.size() - 1));
        }
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> q = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    vector<vector<int>> ans = s.closestNodes(root, q);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
