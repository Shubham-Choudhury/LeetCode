// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        vector<int> ans;
        unordered_map<TreeNode *, TreeNode *> parent;
        dfs(root, parent);
        unordered_set<TreeNode *> seen;
        queue<TreeNode *> q;
        q.push(target);
        seen.insert(target);
        int dist = 0;
        while (!q.empty())
        {
            int n = q.size();
            if (dist == K)
            {
                while (!q.empty())
                {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            for (int i = 0; i < n; ++i)
            {
                TreeNode *u = q.front();
                q.pop();
                if (u->left && seen.find(u->left) == seen.end())
                {
                    q.push(u->left);
                    seen.insert(u->left);
                }
                if (u->right && seen.find(u->right) == seen.end())
                {
                    q.push(u->right);
                    seen.insert(u->right);
                }
                if (parent[u] && seen.find(parent[u]) == seen.end())
                {
                    q.push(parent[u]);
                    seen.insert(parent[u]);
                }
            }
            dist++;
        }
        return ans;
    }

    void dfs(TreeNode *u, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (u->left)
        {
            parent[u->left] = u;
            dfs(u->left, parent);
        }
        if (u->right)
        {
            parent[u->right] = u;
            dfs(u->right, parent);
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *target = root->left;
    int K = 2;
    vector<int> ans = s.distanceK(root, target, K);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}