// Link: https://leetcode.com/problems/k-th-smallest-prime-fraction/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        vector<pair<int, int>> table;

        for (int i = 0; i != arr.size(); i++)
            for (int j = i; j != arr.size(); j++)
                table.push_back({arr[i], arr[j]});

        sort(table.begin(), table.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool
             { return a.first * b.second < a.second * b.first; });
        return {table[k - 1].first, table[k - 1].second};
    }
};

int main()
{
    Solution sol;
    vector<int> A;
    int K;
    vector<int> ans;

    // Output: {1, 2}
    A = {1, 2, 3, 5};
    K = 3;
    ans = sol.kthSmallestPrimeFraction(A, K);
    cout << ans[0] << " " << ans[1] << endl;

    // Output: {1, 5}
    A = {1, 7};
    K = 1;
    ans = sol.kthSmallestPrimeFraction(A, K);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
