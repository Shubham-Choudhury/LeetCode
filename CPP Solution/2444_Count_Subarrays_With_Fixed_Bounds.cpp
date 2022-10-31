// Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        bool minFound = false, maxFound = false;
        int start = 0, minStart = 0, maxStart = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < minK || num > maxK) {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            if (num == minK) {
                minFound = true;
                minStart = i;
            }
            if (num == maxK) {
                maxFound = true;
                maxStart = i;
            }
            if (minFound && maxFound) {
                res += (min(minStart, maxStart) - start + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int>nums = {1,3,5,2,7,5};
    int minK = 1, maxK = 5;
    cout<<s.countSubarrays(nums,minK,maxK);
    return 0;
}