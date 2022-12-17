// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << s.kthSmallest(matrix, 8) << endl;
    return 0;
}
