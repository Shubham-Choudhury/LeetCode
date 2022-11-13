// Link: https://leetcode.com/problems/subarray-sum-equals-k/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << s.subarraySum(nums, k) << endl;
    return 0;
}