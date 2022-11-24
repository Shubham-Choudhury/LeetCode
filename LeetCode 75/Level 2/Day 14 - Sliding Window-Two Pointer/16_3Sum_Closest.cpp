// Link: https://leetcode.com/problems/3sum-closest/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > target)
                    k--;
                else
                    j++;
                if(abs(sum - target) < abs(result - target))
                    result = sum;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution obj;
    cout << obj.threeSumClosest(nums, target);
    return 0;
}