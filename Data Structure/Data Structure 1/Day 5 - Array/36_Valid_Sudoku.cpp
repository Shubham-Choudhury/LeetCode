// Link: https://leetcode.com/problems/valid-sudoku/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> cube;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !row.insert(board[i][j]).second) {
                    return false;
                }
                if (board[j][i] != '.' && !col.insert(board[j][i]).second) {
                    return false;
                }
                int rowIndex = 3 * (i / 3);
                int colIndex = 3 * (i % 3);
                if (board[rowIndex + j / 3][colIndex + j % 3] != '.' && !cube.insert(board[rowIndex + j / 3][colIndex + j % 3]).second) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << s.isValidSudoku(board) << endl;
    return 0;
}