// Link: https://leetcode.com/problems/wiggle-sort-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        int n = nums.size();
        int i = (n - 1) / 2;
        int j = n - 1;
        for (int k = 0; k < n; ++k)
        {
            nums[k] = k % 2 == 0 ? sortedNums[i--] : sortedNums[j--];
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    solution.wiggleSort(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
