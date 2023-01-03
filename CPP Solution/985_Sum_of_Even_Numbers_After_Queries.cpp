// Link: https://leetcode.com/problems/sum-of-even-numbers-after-queries/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
                sum += A[i];
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int val = queries[i][0];
            int index = queries[i][1];
            if (A[index] % 2 == 0)
                sum -= A[index];
            A[index] += val;
            if (A[index] % 2 == 0)
                sum += A[index];
            ans.push_back(sum);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {1, 2, 3, 4};
    vector<vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    vector<int> ans = sol.sumEvenAfterQueries(A, queries);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
