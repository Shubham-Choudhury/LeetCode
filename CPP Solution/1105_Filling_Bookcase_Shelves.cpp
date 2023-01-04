// Link: https://leetcode.com/problems/filling-bookcase-shelves/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelf_width)
    {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int cur_width = 0;
            int cur_height = 0;
            for (int j = i; j >= 1; j--)
            {
                cur_width += books[j - 1][0];
                if (cur_width > shelf_width)
                {
                    break;
                }
                cur_height = max(cur_height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + cur_height);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> books;
    int shelf_width;
    cin >> shelf_width;
    int n;
    cin >> n;
    books.resize(n);
    for (int i = 0; i < n; i++)
    {
        books[i].resize(2);
        for (int j = 0; j < 2; j++)
        {
            cin >> books[i][j];
        }
    }
    cout << sol.minHeightShelves(books, shelf_width) << endl;
    return 0;
}
