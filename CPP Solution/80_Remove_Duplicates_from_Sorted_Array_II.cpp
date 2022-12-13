// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int i = 2;
        for (int j = 2; j < n; ++j)
        {
            if (nums[j] != nums[i - 2])
                nums[i++] = nums[j];
        }
        return i;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
