// Link: https://leetcode.com/problems/minimum-cost-to-make-array-equal/

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long ans = 1e18;
        vector<pair<int,int>> v(n);
        for(int i = 0; i < nums.size(); i++)
            v[i] = {nums[i], cost[i]};
        
        sort(v.begin(), v.end());
        vector<long long> pref(n), suff(n);
        long long c_sum = 0, nc = 0;
        for(int i = 0; i < n; i++){
            pref[i] = (v[i].first * c_sum - nc);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        c_sum = 0, nc = 0;
        for(int i = n - 1; i >= 0; i--){
            ans = min(ans, abs(v[i].first * c_sum - nc) + pref[i]);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int>nums = {1,3,5,2};
    vector<int>cost = {2,3,1,14};
    cout<<s.minCost(nums,cost);
    return 0;
}