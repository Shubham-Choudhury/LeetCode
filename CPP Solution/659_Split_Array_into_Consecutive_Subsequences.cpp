// Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> need;
        for (int num : nums) {
            freq[num]++;
        }
        for (int num : nums) {
            if (freq[num] == 0) {
                continue;
            }
            if (need[num] > 0) {
                need[num]--;
                need[num + 1]++;
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;
            } else {
                return false;
            }
            freq[num]--;
        }
        return true;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    cout << sol.isPossible(nums) << endl;
    return 0;
}
