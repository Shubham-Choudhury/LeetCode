// Link: https://leetcode.com/problems/maximum-ice-cream-bars/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (int i = 0; i < costs.size(); i++)
        {
            if (coins >= costs[i])
            {
                coins -= costs[i];
                res++;
            }
            else
                break;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> costs1 = {1, 3, 2, 4, 1};
    int coins1 = 7;
    cout << s.maxIceCream(costs1, coins1);
    return 0;
}
