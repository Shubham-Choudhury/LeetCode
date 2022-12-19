// Link: https://leetcode.com/problems/contiguous-array/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (m.find(sum) != m.end())
                result = max(result, i - m[sum]);
            else
                m[sum] = i;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1};
    cout << solution.findMaxLength(nums) << endl;
    return 0;
}
