// Link: https://leetcode.com/problems/moving-stones-until-consecutive-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numMovesStonesII(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maxMoves = max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);
        int minMoves = INT_MAX;
        int i = 0, j = 0;
        while (j < n)
        {
            while (stones[j] - stones[i] + 1 > n)
                i++;
            int cost = n - (j - i + 1);
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1)
                cost = 2;
            minMoves = min(minMoves, cost);
            j++;
        }
        return {minMoves, maxMoves};
    }
};

int main()
{
    Solution sol;
    vector<int> stones = {7, 4, 9};
    vector<int> res = sol.numMovesStonesII(stones);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
