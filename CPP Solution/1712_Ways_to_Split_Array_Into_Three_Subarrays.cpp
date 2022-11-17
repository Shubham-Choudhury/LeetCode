// Link: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int waysToSplit(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int a = arr[i], mx = -1, mn = -1;
            int l = i + 1, r = n - 2;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                if (arr[m] - a > arr[n - 1] - arr[m])
                {
                    r = m - 1;
                }
                else
                {
                    if (arr[m] - a >= a)
                    {
                        mx = m;
                        l = m + 1;
                    }
                    else
                        l = m + 1;
                }
            }
            l = i + 1;
            r = n - 2;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                if (arr[m] - a > arr[n - 1] - arr[m])
                {
                    r = m - 1;
                }
                else
                {
                    if (arr[m] - a >= a)
                    {
                        mn = m;
                        r = m - 1;
                    }
                    else
                        l = m + 1;
                }
            }
            if (mx != -1 and mn != -1)
                ans += (mx - mn + 1);

            ans %= mod;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1};
    int result = s.waysToSplit(nums);
    cout << result << endl;
    return 0;
}