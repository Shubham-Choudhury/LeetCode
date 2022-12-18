// Link: https://leetcode.com/problems/132-pattern/

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    { // O(n) Time & Space -> Stack
        if (nums.size() < 3)
            return false;
        stack<int> s3;
        int s2 = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < s2)
                return true;
            else
                while (!s3.empty() && nums[i] > s3.top())
                {
                    s2 = s3.top(), s3.pop();
                }
            s3.push(nums[i]);
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.find132pattern(nums) << endl;
    return 0;
}
