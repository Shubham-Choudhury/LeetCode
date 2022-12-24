// Link: https://leetcode.com/problems/max-chunks-to-make-sorted/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> maxLeft(n);
        vector<int> minRight(n);
        maxLeft[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
        }
        minRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            minRight[i] = min(minRight[i + 1], arr[i]);
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (maxLeft[i] <= minRight[i + 1])
            {
                ans++;
            }
        }
        return ans + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr;
    int ans;

    // Output: 1
    arr = {4, 3, 2, 1, 0};
    ans = sol.maxChunksToSorted(arr);
    cout << ans << endl;

    // Output: 4
    arr = {1, 0, 2, 3, 4};
    ans = sol.maxChunksToSorted(arr);
    cout << ans << endl;

    return 0;
}
