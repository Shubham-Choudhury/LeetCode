// Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    vector<Trie *> arr;
    bool isNum = false;
    Trie()
    {
        arr.resize(2);
    }

    void build(int n)
    {
        auto node = this;
        for (int i = 30; i >= 0; --i)
        {
            int x = (n >> i) & 1;
            if (node->arr[x] == NULL)
                node->arr[x] = new Trie();
            node = node->arr[x];
        }
        node->isNum = true;
    }

    int query(int x, int m, int res, int idx)
    {
        if (res > m)
            return -1; // can't be larger than m.
        if (idx < 0)
            return res; // at the end of the number
        auto node = this;
        int xbit = (x >> idx) & 1;
        int mbit = (m >> idx) & 1;
        if (node->arr[xbit ^ 1])
        { // try the invert bit of x at first.
            int ret = node->arr[xbit ^ 1]->query(x, m, res | ((xbit ^ 1) << idx), idx - 1);
            if (ret >= 0)
                return ret;
        }
        if (node->arr[xbit])
        { // can't get result above, then we try the other path.
            return node->arr[xbit]->query(x, m, res | (xbit << idx), idx - 1);
        }
        return -1;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        Trie trie;
        for (auto x : nums)
        {
            trie.build(x);
        }
        vector<int> ans;
        for (auto &q : queries)
        {
            int x = q[0], m = q[1];
            int res = 0;
            res = trie.query(x, m, res, 30);
            if (res >= 0)
            {
                ans.push_back(res ^ x);
            }
            else
                ans.push_back(-1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4};
    vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
    vector<int> ans = s.maximizeXor(nums, queries);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
