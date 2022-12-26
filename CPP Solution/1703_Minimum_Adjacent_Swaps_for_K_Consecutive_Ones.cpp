// Link: https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums, int k)
    {
        vector<int> ones;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                ones.push_back(i);
        }
        long zeroespref[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                zeroespref[0] = (nums[0] == 0 ? 1 : 0);
            }
            else
            {
                zeroespref[i] = zeroespref[i - 1] + (nums[i] == 0 ? 1 : 0);
            }
        }

        int n = ones.size();
        int right = k - 1;
        int left = 0;
        long mindist = 0;

        // centered at 0
        for (int i = 0; i < k; i++)
        {
            mindist += zeroespref[ones[i]] - zeroespref[ones[0]];
        }

        long curdist = mindist;

        // centered at i
        for (int i = 1; i < n; i++)
        {
            long zeroeschange = zeroespref[ones[i]] - zeroespref[ones[i - 1]];
            curdist += (i - left) * zeroeschange;
            curdist -= (right - i + 1) * zeroeschange;

            while (right + 1 < n)
            {
                long zeroesleft = zeroespref[ones[i]] - zeroespref[ones[left]];
                long zeroesright = zeroespref[ones[right + 1]] - zeroespref[ones[i]];
                if (zeroesright < zeroesleft)
                {
                    curdist -= zeroesleft;
                    curdist += zeroesright;
                    right++;
                    left++;
                }
                else
                    break;
            }
            mindist = min(mindist, curdist);

            if (right == i && right + 1 < n)
            {
                long zeroesleft = zeroespref[ones[i]] - zeroespref[ones[left]];
                long zeroesright = zeroespref[ones[right + 1]] - zeroespref[ones[i]];
                curdist -= zeroesleft;
                curdist += zeroesright;
                right++;
                left++;
            }
        }

        return mindist;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 0, 0, 1, 0, 1};
    int k = 2;
    cout << s.minMoves(nums, k) << endl;
    return 0;
}