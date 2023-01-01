// Link: https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int lcm = nums[i];
            for(int j = i; j < n; j++){
                
                 lcm = (lcm*nums[j])/__gcd(nums[j],lcm);
                if(lcm==k){
                    ans++;}
                if(lcm>k){
                    break;}
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 6, 2, 7, 1};
    int k = 6;
    cout << s.subarrayLCM(nums, k) << endl;
    return 0;
}