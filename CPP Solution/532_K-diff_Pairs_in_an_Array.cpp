// Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> m;
        for (int num : nums)
            m[num]++;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (k > 0 && m.find(it->first + k) != m.end())
                result++;
            else if (k == 0 && it->second > 1)
                result++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << solution.findPairs(nums, 2) << endl;
    return 0;
}
