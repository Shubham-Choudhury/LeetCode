// Link: https://leetcode.com/problems/valid-tic-tac-toe-state/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int x = 0, o = 0;
        for (auto &row : board)
        {
            for (auto &c : row)
            {
                if (c == 'X')
                    ++x;
                else if (c == 'O')
                    ++o;
            }
        }
        if (o > x || x - o > 1)
            return false;
        if (win(board, 'X') && x == o)
            return false;
        if (win(board, 'O') && x > o)
            return false;
        return true;
    }

    bool win(vector<string> &board, char player)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;
        return false;
    }
};

int main()
{
    Solution sol;
    vector<string> board;
    bool result;

    // Output: true
    board = {"O  ", "   ", "   "};
    result = sol.validTicTacToe(board);
    cout << result << endl;

    // Output: false
    board = {"XOX", " X ", "   "};
    result = sol.validTicTacToe(board);
    cout << result << endl;

    // Output: false
    board = {"XXX", "   ", "OOO"};
    result = sol.validTicTacToe(board);
    cout << result << endl;

    // Output: false
    board = {"XOX", "O O", "XOX"};
    result = sol.validTicTacToe(board);
    cout << result << endl;

    return 0;
}
