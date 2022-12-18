// Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                result.push_back(index + 1);
            nums[index] = -nums[index];
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = s.findDuplicates(nums);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
