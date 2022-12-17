// Link: https://leetcode.com/problems/single-number-iii/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorResult = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorResult ^= nums[i];
        }
        int Index1 = FindTheFirst1(xorResult);

        int num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & (1 << Index1))
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }
        vector<int> result;
        if (num1 != 0 || num2 != 0)
        {

            result.push_back(num1);
            result.push_back(num2);
        }
        return result;
    }
    int FindTheFirst1(int i)
    {
        if (i == 0)
            return -1;

        int index = 0;
        while ((i & 1) == 0)
        {
            i = (i >> 1);
            index++;
        }
        return index;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = Solution().singleNumber(nums);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    return 0;
}
