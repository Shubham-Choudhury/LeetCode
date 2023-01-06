// Link: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int oneDelete = 0, noDelete = arr[0], ans = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            oneDelete = max(noDelete, oneDelete + arr[i]);
            noDelete = max(noDelete + arr[i], arr[i]);
            ans = max(ans, max(oneDelete, noDelete));
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, -2, 0, 3};
    cout << s.maximumSum(arr);
    return 0;
}
