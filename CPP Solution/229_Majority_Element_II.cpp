// Link: https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res;
        if (n == 0)
            return res;
        int a = nums[0], b = nums[0], ca = 0, cb = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == a)
                ca++;
            else if (nums[i] == b)
                cb++;
            else if (ca == 0)
            {
                a = nums[i];
                ca = 1;
            }
            else if (cb == 0)
            {
                b = nums[i];
                cb = 1;
            }
            else
            {
                ca--;
                cb--;
            }
        }
        ca = 0;
        cb = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == a)
                ca++;
            else if (nums[i] == b)
                cb++;
        }
        if (ca > n / 3)
            res.push_back(a);
        if (cb > n / 3)
            res.push_back(b);
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> nums = {3, 2, 3};
    vector<int> res = a.majorityElement(nums);
    for (auto &a : res)
        cout << a << " ";
    cout << endl;
    nums = {1, 1, 1, 3, 3, 2, 2, 2};
    res = a.majorityElement(nums);
    for (auto &a : res)
        cout << a << " ";
    cout << endl;
    return 0;
}
