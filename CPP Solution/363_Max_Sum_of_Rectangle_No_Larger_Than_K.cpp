// Link: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

class Solution
{

public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        for (int i = 0; i < m; i++)
        {
            vector<int> sums(n, 0);

            for (int j = i; j < m; j++)
            {
                for (int c = 0; c < n; c++)
                {
                    sums[c] += matrix[j][c];
                }

                set<int> accuSet;
                accuSet.insert(0);
                int accu = 0;
                for (int sum : sums)
                {
                    accu += sum;
                    auto it = accuSet.lower_bound(accu - k);
                    if (it != accuSet.end())
                    {
                        ans = max(ans, accu - *it);
                    }
                    accuSet.insert(accu);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix;
    int k;
    int res;

    matrix = {{1, 0, 1}, {0, -2, 3}};
    k = 2;
    res = obj.maxSumSubmatrix(matrix, k);
    cout << res << endl;

    matrix = {{2, 2, -1}};
    k = 3;
    res = obj.maxSumSubmatrix(matrix, k);
    cout << res << endl;

    return 0;
}
