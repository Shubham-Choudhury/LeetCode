// Link: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();

        int pos_len = 0;

        int neg_len = 0;

        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                pos_len = 0;

                neg_len = 0;
            }
            else if (nums[i] > 0)
            {
                pos_len++;

                if (neg_len != 0)
                {
                    neg_len++;
                }
            }
            else if (nums[i] < 0)
            {

                int prev_neg_len = neg_len;

                neg_len = pos_len + 1;

                if (prev_neg_len == 0)
                {
                    pos_len = 0;
                }
                else
                {
                    pos_len = prev_neg_len + 1;
                }
            }

            maxi = max(maxi, pos_len);
        }

        return maxi;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, -2, -3, 0, 1};
    cout << s.getMaxLen(nums) << endl;
    return 0;
}