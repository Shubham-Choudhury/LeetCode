// Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > 0) {
                for (int i = 1; i < k; i++) {
                    if (mp.find(it->first + i) == mp.end()) return false;
                    if (mp[it->first + i] < it->second) return false;
                    mp[it->first + i] -= it->second;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 3, 4, 4, 5, 6};
    int k = 4;
    cout << sol.isPossibleDivide(nums, k) << endl;
    return 0;
}
