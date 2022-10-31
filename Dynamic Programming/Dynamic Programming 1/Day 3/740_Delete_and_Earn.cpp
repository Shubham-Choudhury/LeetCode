// Link: https://leetcode.com/problems/delete-and-earn/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};

int main(){
    vector<int> nums = {3,4,2};
    Solution obj;
    int ans = obj.deleteAndEarn(nums);
    cout << ans << endl;
    return 0;
}