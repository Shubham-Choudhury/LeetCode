// Link: https://leetcode.com/problems/arithmetic-subarrays/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        for (int i = 0; i < l.size(); i++) {
            vector<int> subarray;
            for (int j = l[i]; j <= r[i]; j++) {
                subarray.push_back(nums[j]);
            }
            result.push_back(isArithmeticSubarray(subarray));
        }
        return result;
    }
    
    bool isArithmeticSubarray(vector<int>& subarray) {
        sort(subarray.begin(), subarray.end());
        int diff = subarray[1] - subarray[0];
        for (int i = 2; i < subarray.size(); i++) {
            if (subarray[i] - subarray[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> nums = {4, 6, 5, 9, 3, 7};
    vector<int> l = {0, 0, 2};
    vector<int> r = {2, 3, 5};
    Solution sol;
    vector<bool> result = sol.checkArithmeticSubarrays(nums, l, r);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}