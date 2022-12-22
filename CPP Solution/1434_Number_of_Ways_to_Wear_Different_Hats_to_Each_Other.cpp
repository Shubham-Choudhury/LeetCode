// Link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numberWays(vector<vector<int>> &hats)
    {
        int kMod = 1e9 + 7;
        int n = hats.size();
        vector<long> dp(1 << n); // the number of ways wearing hat with current status
        dp[0] = 1;
        unordered_map<int, vector<int>> Map; // hat to different people
        for (int i = 0; i < hats.size(); i++)
        {
            for (auto &x : hats[i])
            {
                Map[x].push_back(i);
            }
        }

        for (int i = 1; i <= 40; i++)
        {
            vector<long> temp = dp;
            for (int j = 0; j < (1 << n); j++)
            {
                if (!Map.count(i))
                {
                    break;
                }
                for (auto &x : Map[i])
                {
                    if ((j >> x) & 1 == 1)
                        continue;
                    temp[j + (1 << x)] = (temp[j + (1 << x)] + dp[j]) % kMod;
                }
            }

            dp = temp;
        }

        return dp.back();
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> hats = {{3, 4}, {4, 5}, {5}};
    int res = sol.numberWays(hats);
    cout << res << endl;
    return 0;
}
