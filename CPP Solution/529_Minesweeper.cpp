// Link: https://leetcode.com/problems/minesweeper/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getAdjMines(vector<vector<char>>& board, int x, int y)
    {
        int mines = 0;
        if (x-1 >= 0)
        {
            mines += (board[x-1][y] == 'M'? 1: 0);
            if (y-1 >=0) mines += (board[x-1][y-1] == 'M'? 1 : 0);
            if (y+1 < board[x].size()) mines += (board[x-1][y+1] == 'M'? 1 : 0);
        }
        if (x+1 < board.size())
        {
            mines += (board[x+1][y] == 'M'? 1: 0);
            if (y-1 >=0) mines += (board[x+1][y-1] == 'M'? 1 : 0);
            if (y+1 < board[x+1].size()) mines += (board[x+1][y+1] == 'M'? 1 : 0);
        }
        if (y-1 >= 0)
        {
            mines += (board[x][y-1] == 'M'? 1:0);
        }
        if (y+1 < board[x].size())
        {
            mines += (board[x][y+1] == 'M'? 1:0);
        }
        return mines;
    }
    
    void openSquares(vector<vector<char>>& board, int x, int y)
    {
        //If outside the boundaries of board, return
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size())
            return;
        
        //If the square is already revealed, return
        if (board[x][y] == 'X' || board[x][y] == 'B' || (board[x][y] >= '1' && board[x][y] <= '8'))
            return;
        
        //We hit a mine!
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return;
        }
        
        //Get adjacent mines and recursively reveal tiles if this is a blank tile
        int adjMines = getAdjMines(board, x, y);
        if (adjMines > 0)
            board[x][y] = adjMines + '0';
        else
        {
            board[x][y] = 'B';
            //Open all adjacent squares
            //Adj squares can't have mines
            for(int i=x-1; i <= x+1; i++)
                for(int j=y-1; j <= y+1; j++)
                    openSquares(board, i, j);
        }
        return;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        openSquares(board, click[0], click[1]);
        return board;
    }
};


int main() {
    Solution solution;
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'M', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {3, 0};
    vector<vector<char>> result = solution.updateBoard(board, click);
    for (vector<char> row : result) {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
