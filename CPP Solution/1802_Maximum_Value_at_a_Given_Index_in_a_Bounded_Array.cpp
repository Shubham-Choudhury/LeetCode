// Link: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long calSum(long n)
    {
        return (n * (n + 1)) / 2;
    }

    bool satisfy(int mid, int n, int index, int maxSum)
    {

        int leftSize = index;
        int rightSize = n - 1 - index;
        long refMid = mid - 1;

        long rightSum = 0;
        long leftSum = 0;

        if (refMid > rightSize)
        {
            long rightExtraSize = refMid - rightSize;
            rightSum = calSum(refMid) - calSum(rightExtraSize);
        }
        else
        {
            long rightExtraSize = rightSize - refMid;
            rightSum = calSum(refMid) + rightExtraSize;
        }

        if (refMid > leftSize)
        {
            long leftExtraSize = refMid - leftSize;
            leftSum = calSum(refMid) - calSum(leftExtraSize);
        }
        else
        {
            long leftExtraSize = leftSize - refMid;
            leftSum = calSum(refMid) + leftExtraSize;
        }

        return mid + leftSum + rightSum <= maxSum;
    }

    int maxValue(int n, int index, int maxSum)
    {
        int l = 0;
        int h = maxSum;
        int ans = 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (satisfy(mid, n, index, maxSum))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.maxValue(4, 2, 6);
    return 0;
}