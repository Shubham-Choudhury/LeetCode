// Link: https://leetcode.com/problems/valid-sudoku/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    for (int i = 0 ; i < 9 ; i += 3){
        for (int j = 0 ; j < 9 ; j += 3){
            bool check[10] = {0};
            for (int m = i ; m < i+3 ; m++){
                for (int n = j ; n < j+3 ; n++){
                    if (board[m][n] != '.'){
                        if (check[board[m][n]-'0']){
                            return false;
                        } else {
                            check[board[m][n]-'0'] = true;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0 ; i < 9 ; i++){
        bool check_x[10] = {0};
        bool check_y[10] = {0};
        for (int j = 0 ; j < 9 ; j++){
            if (board[i][j] != '.'){
                if (check_x[board[i][j]-'0']) {
                    return false;
                } else {
                    check_x[board[i][j]-'0'] = true;
                }
            }
            if (board[j][i] != '.'){
                if (check_y[board[j][i]-'0']) {
                    return false;
                } else {
                    check_y[board[j][i]-'0'] = true;
                }
            }
        }
    }
    return true;
}

int main() {
    char* board[] = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
    int boardRowSize = sizeof(board) / sizeof(char*);
    int boardColSize = sizeof(board[0]) / sizeof(char);
    printf("%d", isValidSudoku(board, boardRowSize, &boardColSize));
    return 0;
}