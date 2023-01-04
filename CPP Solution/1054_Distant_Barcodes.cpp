// Link: https://leetcode.com/problems/distant-barcodes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        int n = barcodes.size();
        unordered_map<int, int> mp;
        for (auto &barcode : barcodes)
            mp[barcode]++;
        priority_queue<pair<int, int>> pq;
        for (auto &x : mp)
            pq.push({x.second, x.first});
        vector<int> res(n);
        int i = 0;
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            while (p.first--)
            {
                res[i] = p.second;
                i += 2;
                if (i >= n)
                    i = 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> barcodes = {1, 1, 1, 2, 2, 2};
    vector<int> res = sol.rearrangeBarcodes(barcodes);
    for (auto &x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
