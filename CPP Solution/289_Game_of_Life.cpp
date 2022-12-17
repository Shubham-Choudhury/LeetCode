// Link: https://leetcode.com/problems/game-of-life/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int count = 0;
                if (i > 0 && j > 0 && board[i - 1][j - 1] == 1)
                {
                    ++count;
                }
                if (i > 0 && board[i - 1][j] == 1)
                {
                    ++count;
                }
                if (i > 0 && j < n - 1 && board[i - 1][j + 1] == 1)
                {
                    ++count;
                }
                if (j > 0 && board[i][j - 1] == 1)
                {
                    ++count;
                }
                if (j < n - 1 && board[i][j + 1] == 1)
                {
                    ++count;
                }
                if (i < m - 1 && j > 0 && board[i + 1][j - 1] == 1)
                {
                    ++count;
                }
                if (i < m - 1 && board[i + 1][j] == 1)
                {
                    ++count;
                }
                if (i < m - 1 && j < n - 1 && board[i + 1][j + 1] == 1)
                {
                    ++count;
                }
                if (board[i][j] == 1)
                {
                    if (count == 2 || count == 3)
                    {
                        result[i][j] = 1;
                    }
                }
                else
                {
                    if (count == 3)
                    {
                        result[i][j] = 1;
                    }
                }
            }
        }
        board = result;
    }
};

int main()
{
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution().gameOfLife(board);
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
