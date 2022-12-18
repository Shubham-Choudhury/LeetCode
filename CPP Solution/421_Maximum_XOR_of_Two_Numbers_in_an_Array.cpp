// Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int result = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--)
        {
            mask = mask | (1 << i);
            unordered_set<int> set;
            for (int num : nums)
            {
                set.insert(num & mask);
            }
            int temp = result | (1 << i);
            for (int prefix : set)
            {
                if (set.find(temp ^ prefix) != set.end())
                {
                    result = temp;
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << s.findMaximumXOR(nums) << endl;
    return 0;
}
