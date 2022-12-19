// Link: https://leetcode.com/problems/continuous-subarray-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(k != 0) sum %= k;
            if(m.find(sum) != m.end()) {
                if(i - m[sum] > 1) return true;
            } else {
                m[sum] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {23, 2, 4, 6, 7};
    cout << s.checkSubarraySum(nums, 6) << endl;
    return 0;
}
