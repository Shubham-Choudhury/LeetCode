// Link: https://leetcode.com/problems/target-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, S, 0, 0);
    }
private:
    int findTargetSumWays(vector<int>& nums, int S, int sum, int index) {
        if(index == nums.size()) {
            return sum == S ? 1 : 0;
        }
        return findTargetSumWays(nums, S, sum + nums[index], index + 1) + findTargetSumWays(nums, S, sum - nums[index], index + 1);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 1, 1, 1, 1};
    cout << s.findTargetSumWays(v, 3) << endl;
    return 0;
}
