// Link: https://leetcode.com/problems/reverse-pairs/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    int merge(vector<int> &nums, int l, int m, int r)
    {
        int count = 0;
        int i = l, j = m + 1;
        while(i <= m && j <= r)
        {
            if(nums[i] > 2 * (long)nums[j])
            {
                count += m - i + 1;
                j++;
            }
            else
                i++;
        }
        i = l, j = m + 1;
        vector<int> temp;
        while(i <= m && j <= r)
        {
            if(nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i <= m)
            temp.push_back(nums[i++]);
        while(j <= r)
            temp.push_back(nums[j++]);
        for(int i = l; i <= r; i++)
            nums[i] = temp[i - l];
        return count;
    }
    int mergeSort(vector<int> &nums, int l, int r)
    {
        if(l >= r)
            return 0;
        int m = l + (r - l) / 2;
        int count = mergeSort(nums, l, m) + mergeSort(nums, m + 1, r);
        return count + merge(nums, l, m, r);
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    Solution sol;
    cout << sol.reversePairs(nums) << endl;

    return 0;
}