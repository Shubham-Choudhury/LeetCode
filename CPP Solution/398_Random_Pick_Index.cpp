// Link: https://leetcode.com/problems/random-pick-index/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> callCount;
    vector<int> arr;
    Solution(vector<int> &nums)
    {
        callCount.clear();
        arr.clear();
        for (int i = 0; i < nums.size(); i++)
        {
            callCount.push_back(0);
            arr.push_back(nums[i]);
        }
    }
    int pick(int target)
    {
        int minCall = INT_MAX;
        int index;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                if (minCall > callCount[i])
                {
                    index = i;
                    minCall = callCount[i];
                }
            }
        }
        callCount[index]++;
        return index;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution s(nums);
    cout << s.pick(3) << endl;
    return 0;
}
