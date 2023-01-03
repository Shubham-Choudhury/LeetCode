// Link: https://leetcode.com/problems/longest-turbulent-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int n = size(arr);
        if (n == 1)
            return n;

        // int dp[n];
        int mx = 1, cnt = 1;
        // for index-0 and index-1 - we handle externally{I told in previous too}
        if (arr[1] != arr[0])
            cnt++;
        mx = max(mx, cnt);

        for (int i = 2; i < n; i++)
        {
            if (arr[i - 2] > arr[i - 1] and arr[i - 1] < arr[i] or arr[i - 2] < arr[i - 1] and arr[i - 1] > arr[i])
                cnt++;
            else
                arr[i] != arr[i - 1] ? cnt = 2 : cnt = 1;

            mx = max(mx, cnt);
        }
        return mx;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {9, 4, 2, 10, 7, 8, 8, 1, 9};
    cout << sol.maxTurbulenceSize(arr) << endl;
    return 0;
}
