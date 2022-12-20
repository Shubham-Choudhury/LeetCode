// Link: https://leetcode.com/problems/maximum-length-of-pair-chain/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
             { return a[1] < b[1]; });
        int ans = 0, end = INT_MIN;
        for (auto p : pairs)
        {
            if (p[0] > end)
            {
                end = p[1];
                ans++;
            }
        }
        return ans;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> pairs = {
        {1, 2},
        {2, 3},
        {3, 4}};
    int res = sol.findLongestChain(pairs);
    cout << res << endl;
    return 0;
}
