// Link: https://leetcode.com/problems/contains-duplicate-ii/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
                return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,1,2,3};
    cout << s.containsNearbyDuplicate(nums, 3) << endl;
    return 0;
}