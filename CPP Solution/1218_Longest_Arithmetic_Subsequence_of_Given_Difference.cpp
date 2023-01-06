// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]] = mp[arr[i] - difference] + 1;
            res = max(res, mp[arr[i]]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4};
    int difference1 = 1;
    cout << s.longestSubsequence(arr1, difference1);
    return 0;
}

