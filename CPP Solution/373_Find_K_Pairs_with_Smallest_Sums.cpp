// Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> res;
        if (nums1.empty() || nums2.empty())
            return res;
        vector<int> index(nums1.size(), 0);
        while (k-- > 0)
        {
            int minSum = INT_MAX;
            int minIndex = -1;
            for (int i = 0; i < nums1.size(); i++)
            {
                if (index[i] < nums2.size() && nums1[i] + nums2[index[i]] < minSum)
                {
                    minSum = nums1[i] + nums2[index[i]];
                    minIndex = i;
                }
            }
            if (minIndex == -1)
                break;
            res.push_back(make_pair(nums1[minIndex], nums2[index[minIndex]]));
            index[minIndex]++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    vector<pair<int, int>> res = s.kSmallestPairs(nums1, nums2, 3);
    for (auto p : res)
        cout << p.first << " " << p.second << endl;
    return 0;
}
