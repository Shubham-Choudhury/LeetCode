// Link: https://leetcode.com/problems/building-boxes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(int n)
    {
        vector<int> dp(1, 1), presum(1, 1);
        while (presum.back() < n)
        {
            dp.push_back(dp.back() + dp.size() + 1);
            presum.push_back(presum.back() + dp.back());
        }

        if (presum.back() == n)
            return dp.back();

        int ans = dp.end()[-2], cnt = 1;
        for (int i = 1; i <= dp.size(); ++i)
        {
            cnt += i;
            ans += 1;
            if (cnt > n - presum.end()[-2])
                break;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n, result;

    // Output: 3
    n = 3;
    result = sol.minimumBoxes(n);
    cout << result << endl;

    // Output: 4
    n = 4;
    result = sol.minimumBoxes(n);
    cout << result << endl;

    // Output: 6
    n = 10;
    result = sol.minimumBoxes(n);
    cout << result << endl;

    // Output: 10
    n = 15;
    result = sol.minimumBoxes(n);
    cout << result << endl;

    return 0;
}
