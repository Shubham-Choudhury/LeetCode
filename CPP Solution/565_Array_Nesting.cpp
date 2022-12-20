// Link: https://leetcode.com/problems/array-nesting/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> visited;
        for (int i = 0; i < nums.size(); ++i) {
            if (visited.count(i)) {
                continue;
            }
            int len = 0;
            int j = i;
            while (!visited.count(j)) {
                visited.insert(j);
                j = nums[j];
                len++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};

int main() {
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    Solution sol;
    cout << sol.arrayNesting(nums) << endl;
    return 0;
}
