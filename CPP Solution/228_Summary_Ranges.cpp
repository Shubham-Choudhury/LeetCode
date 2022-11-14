// Link: https://leetcode.com/problems/summary-ranges/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }
        int start = nums[0];
        int end = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                if (start == end) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
                end = nums[i];
            }
        }
        if (start == end) {
            result.push_back(to_string(start));
        } else {
            result.push_back(to_string(start) + "->" + to_string(end));
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> result = s.summaryRanges(nums);
    for (string str : result) {
        cout << str << endl;
    }
    return 0;
}