// Link: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &A, int L, int R)
    {
        int end = A.size();
        int rangeIdx = end;
        int res = 0;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            if (A[i] >= L)
            {
                rangeIdx = i;
                if (A[i] > R)
                {
                    end = i;
                }
            }
            res += end - rangeIdx;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int left, right, result;

    // Output: 3
    nums = {2, 1, 4, 3};
    left = 2;
    right = 3;
    result = sol.numSubarrayBoundedMax(nums, left, right);
    cout << result << endl;

    // Output: 5
    nums = {2, 9, 2, 5, 6};
    left = 2;
    right = 8;
    result = sol.numSubarrayBoundedMax(nums, left, right);
    cout << result << endl;

    // Output: 7
    nums = {73, 55, 36, 5, 55, 14, 9, 7, 72, 52};
    left = 32;
    right = 69;
    result = sol.numSubarrayBoundedMax(nums, left, right);
    cout << result << endl;

    return 0;
}
