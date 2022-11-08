// Link: https://leetcode.com/problems/valid-triangle-number/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int binarySearch(vector<int> &nums, int l, int r, int sum)
    {
        while(r>=l && r<nums.size())
        {
            int mid = (r-l)/2+l;
            if(nums[mid]>=sum)
                r = mid-1;
            else
                l = mid+1;
        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-2; i++)
        {
            int k = i+2;
            for(int j=i+1; j<n-1 && nums[i]!=0; j++)
            {
                k = binarySearch(nums, k, n-1, nums[i]+nums[j]);
                ans+=k-j-1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {7,0,0,0};
    cout << sol.triangleNumber(nums) << endl;
    return 0;
}