// Link: https://leetcode.com/problems/maximum-gap/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;
        vector<vector<int>> bucket(bucketSize, vector<int>());
        for(int i = 0; i < n; i++){
            int idx = (nums[i] - minVal) / d;
            if(bucket[idx].empty()){
                bucket[idx].push_back(nums[i]);
                bucket[idx].push_back(nums[i]);
            }else{
                bucket[idx][0] = min(bucket[idx][0], nums[i]);
                bucket[idx][1] = max(bucket[idx][1], nums[i]);
            }
        }
        int res = 0;
        int prev = -1;
        for(int i = 0; i < bucketSize; i++){
            if(bucket[i].empty()) continue;
            if(prev != -1){
                res = max(res, bucket[i][0] - bucket[prev][1]);
            }
            prev = i;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,6,9,1};
    int result = solution.maximumGap(nums);
    cout << result << endl;
    return 0;
}
