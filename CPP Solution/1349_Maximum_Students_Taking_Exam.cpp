// Link: https://leetcode.com/problems/maximum-students-taking-exam/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxStudents(vector<vector<char>> &seats)
    {
        int m = seats.size();
        int n = seats[0].size();

        vector<int> arr; // vector to store mask

        // calculating mask column-wise
        for (int i = 0; i < n; ++i)
        {
            int num = 0;
            for (int j = 0; j < m; ++j)
            {
                num += pow(2, j) * (seats[j][i] == '.');
            }
            arr.push_back(num);
        }

        // dp[i][j] = maximum number that can be placed till ith column if number of students in ith column is equal to number of set bits in j, provided it does not violate the rules.
        vector<vector<int>> dp(n, vector<int>(1 << m, -1));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < (1 << m); ++j)
            {
                // student should only sit on not-broken seat.
                if ((arr[i] | j) == arr[i])
                {
                    // for the first column
                    if (i == 0)
                    {
                        dp[i][j] = __builtin_popcount(j);
                        continue;
                    }

                    // for the rest column
                    for (int k = 0; k < (1 << m); ++k)
                    {
                        if (dp[i - 1][k] != -1)
                        {

                            // students should not be sharing adjacent seat or the adjacent corners.
                            if (!(j & k) && !((j << 1) & k) && !((j >> 1) & k))
                            {
                                dp[i][j] = max(dp[i][j], dp[i - 1][k] + __builtin_popcount(j));
                            }
                        }
                    }
                }
            }
        }

        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> seats;

    seats = {{'#', '.', '#', '#', '.', '#'},
             {'.', '#', '#', '#', '#', '.'},
             {'#', '.', '#', '#', '.', '#'}};
    cout << sol.maxStudents(seats) << endl;

    seats = {{'.', '#'},
             {'#', '#'},
             {'#', '.'},
             {'#', '#'},
             {'.', '#'}};
    cout << sol.maxStudents(seats) << endl;

    seats = {{'#', '.', '#', '#', '.', '#'},
             {'.', '#', '#', '#', '#', '.'},
             {'#', '.', '#', '#', '.', '#'}};
    cout << sol.maxStudents(seats) << endl;

    return 0;
}
