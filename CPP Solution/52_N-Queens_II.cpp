// Link: https://leetcode.com/problems/n-queens-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> board(n, -1);
        totalNQueens(result, board, 0);
        return result;
    }
    
    void totalNQueens(int& result, vector<int>& board, int row) {
        if (row == board.size()) {
            result++;
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (isValid(board, row, col)) {
                board[row] = col;
                totalNQueens(result, board, row + 1);
                board[row] = -1;
            }
        }
    }
    
    bool isValid(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col)
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i] == j)
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i] == j)
                return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.totalNQueens(4) << endl;
    return 0;
}