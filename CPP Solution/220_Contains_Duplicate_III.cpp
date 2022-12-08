// Link: https://leetcode.com/problems/contains-duplicate-iii/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i - k - 1]);
            auto pos = window.lower_bound((long)nums[i] - t);
            if (pos != window.end() && *pos - nums[i] <= t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    int t = 0;
    Solution sol;
    cout << sol.containsNearbyAlmostDuplicate(nums, k, t) << endl;
    
    return 0;
}
