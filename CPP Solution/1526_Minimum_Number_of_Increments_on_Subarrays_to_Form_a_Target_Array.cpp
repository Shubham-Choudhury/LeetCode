// Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; i++) {
            ans += max(0, target[i] - target[i - 1]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> target;
    int ans;

    // Output: 3
    target = {1,2,3,2,1};
    ans = sol.minNumberOperations(target);
    cout << ans << endl;

    // Output: 1
    target = {3,1,1,2};
    ans = sol.minNumberOperations(target);
    cout << ans << endl;

    // Output: 4
    target = {3,1,5,4,2};
    ans = sol.minNumberOperations(target);
    cout << ans << endl;

    // Output: 7
    target = {1,1,1,1};
    ans = sol.minNumberOperations(target);
    cout << ans << endl;

    return 0;
}