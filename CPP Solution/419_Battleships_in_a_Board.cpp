// Link: https://leetcode.com/problems/battleships-in-a-board/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int result = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'X')
                {
                    result++;
                    int k = j + 1;
                    while (k < board[i].size() && board[i][k] == 'X')
                    {
                        board[i][k] = '.';
                        k++;
                    }
                    k = i + 1;
                    while (k < board.size() && board[k][j] == 'X')
                    {
                        board[k][j] = '.';
                        k++;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    cout << s.countBattleships(board) << endl;
    return 0;
}
