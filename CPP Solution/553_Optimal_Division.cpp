// Link: https://leetcode.com/problems/optimal-division/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string result = "";
        if (nums.size() == 0)
            return result;
        if (nums.size() == 1)
            return to_string(nums[0]);
        if (nums.size() == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        result += to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < nums.size(); i++)
            result += "/" + to_string(nums[i]);
        result += ")";
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1000, 100, 10, 2};
    cout << s.optimalDivision(nums) << endl;
    return 0;
}
