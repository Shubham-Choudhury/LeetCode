// Link: https://leetcode.com/problems/destroy-sequential-targets/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for(auto n: nums){
            int r = n % space;  
            mp[r]++;  
            if(mx < mp[r])  mx = mp[r];  
        }
        for(auto n: nums){ 
            if(mx == mp[n%space])  ans = min(ans, n);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,7,8,1,1,5};
    cout<<s.destroyTargets(nums, 2);
    return 0;
}