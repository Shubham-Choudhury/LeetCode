// Link: https://leetcode.com/problems/make-array-strictly-increasing/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
#include <climits>
using namespace std;

class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int L1 = arr1.size(), L2 = arr2.size();
        int INF = 10000;
        sort(arr2.begin(), arr2.end()); //

        vector<vector<int>> dp(L1 + 1, vector<int>(L2 + 2, INF));
        vector<vector<int>> dp2(L1 + 1, vector<int>(L2 + 2, INF));

        for (int index2 = L2; index2 >= 0; index2--)
        {
            dp[L1][index2] = dp2[L1][index2] = 0;
        }

        for (int index1 = L1 - 1; index1 >= 0; index1--)
        {
            for (int index2 = L2; index2 >= 0; index2--)
            {
                int previous = -1;

                if (index1 - 1 >= 0)
                {
                    previous = arr1[index1 - 1];
                }

                if (arr1[index1] > previous)
                {
                    dp[index1][index2] = min(dp[index1][index2], dp[index1 + 1][index2]);
                }

                if (index2 < L2)
                {
                    dp[index1][index2] = min(dp[index1][index2], dp[index1][index2 + 1]);

                    if (arr2[index2] > previous)
                    {
                        dp[index1][index2] = min(dp[index1][index2], dp2[index1 + 1][index2 + 1] + 1);
                    }
                }
                if (index2 - 1 >= 0)
                {
                    previous = arr2[index2 - 1];
                    if (arr1[index1] > previous)
                    {
                        dp2[index1][index2] = min(dp2[index1][index2], dp[index1 + 1][index2]);
                    }

                    if (index2 < L2)
                    {
                        dp2[index1][index2] = min(dp2[index1][index2], dp2[index1][index2 + 1]);

                        if (arr2[index2] > previous)
                        {
                            dp2[index1][index2] = min(dp2[index1][index2], dp2[index1 + 1][index2 + 1] + 1);
                        }
                    }
                }
            }
        }
        int r = dp[0][0];
        if (r >= INF)
            return -1;
        return r;
    }
};

int main()
{
    Solution sol;
    vector<int> arr1, arr2;
    int ans;

    // Output: 1
    arr1 = {1, 5, 3, 6, 7}, arr2 = {1, 3, 2, 4};
    ans = sol.makeArrayIncreasing(arr1, arr2);
    cout << ans << endl;

    // Output: 2
    arr1 = {1, 5, 3, 6, 7}, arr2 = {4, 3, 1};
    ans = sol.makeArrayIncreasing(arr1, arr2);
    cout << ans << endl;

    return 0;
}