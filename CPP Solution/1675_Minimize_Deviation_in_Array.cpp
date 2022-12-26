// Link: https://leetcode.com/problems/minimize-deviation-in-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1)
                nums[i] *= 2;
            s.insert(nums[i]);
        }
        int ans = *s.rbegin() - *s.begin();
        while (*s.rbegin() % 2 == 0) {
            int x = *s.rbegin();
            s.erase(x);
            s.insert(x / 2);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 1, 5, 20, 3};
    cout << s.minimumDeviation(nums) << endl;
    return 0;
}