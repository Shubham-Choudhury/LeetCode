// Link: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        vector<int> sums = {0}, cur = {};

        for (const auto &row : mat)
        {
            for (const int cel : row)
            {
                for (const int sum : sums)
                {
                    cur.push_back(cel + sum);
                }
            }

            int nth = min((int)cur.size(), k);

            nth_element(cur.begin(), cur.begin() + nth, cur.end());

            sums.clear();
            copy(cur.begin(), cur.begin() + nth, back_inserter(sums));
            cur.clear();
        }

        return *max_element(sums.begin(), sums.end());
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> mat = {{1, 3, 11}, {2, 4, 6}};
    int k = 5;
    int res = sol.kthSmallest(mat, k);
    cout << res << endl;
    return 0;
}
