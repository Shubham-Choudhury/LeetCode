// Link: https://leetcode.com/problems/surrounded-regions/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        if (m == 0)
            return;
        if (n == 1 || m == 1)
            return;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                q.push({i, 0});
                board[i][0] = '1';
            }
            if (board[i][m - 1] == 'O')
            {
                q.push({i, m - 1});
                board[i][m - 1] = '1';
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O')
            {
                q.push({0, i});
                board[0][i] = '1';
            }
            if (board[n - 1][i] == 'O')
            {
                q.push({n - 1, i});
                board[n - 1][i] = '1';
            }
        }

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];

                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O')
                {
                    q.push({x, y});
                    board[x][y] = '1';
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};

int main()
{
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution obj;
    obj.solve(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}