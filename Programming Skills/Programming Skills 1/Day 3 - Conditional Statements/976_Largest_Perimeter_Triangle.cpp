// Link: https://leetcode.com/problems/largest-perimeter-triangle/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=n-1;i>=2;i--)
        {
            if(nums[i-1]+nums[i-2]>nums[i])
            {
                return nums[i-1]+nums[i-2]+nums[i];
            }
        }
        return 0;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution s;
    cout << s.largestPerimeter(nums) << endl;
    return 0;
}
