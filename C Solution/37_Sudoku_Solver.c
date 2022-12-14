// Link: https://leetcode.com/problems/sudoku-solver/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <setjmp.h>
#include <string.h>

int getBoxId (int row,int col) {
  int rowVal = (row / 3) * 3;
  int colVal = col / 3;

  return rowVal + colVal;
}

bool isValid (int *box,int *row,int *col,int num) {
  if (box[num - 1] || row[num - 1] || col[num - 1])
    return false;
  else
    return true;

}

static int maxR;
static int maxC;

bool solveBacktrack(char **board, int box_ht[maxR][maxC], int row_ht[maxR][maxC], int col_ht[maxR][maxC], int r, int c)
{
    if ((r == maxR) || (c == maxC)) {
        return true;
    } else {
       if (board[r][c] == '.') {
            for (int num = 1; num <= 9; num++) { 
                board[r][c] = num + '0';
                
                int boxId = getBoxId(r, c);
                int *box = box_ht[boxId];
                int *row = row_ht[r];
                int *col = col_ht[c];
                
                if (isValid(box, row, col, num)) {
                    box[num - 1] = 1;
                    row[num - 1] = 1;
                    col[num - 1] = 1;

                    if (c == maxC - 1) {
                        if (solveBacktrack(board, box_ht, row_ht, col_ht, r + 1, 0))
                            return true;
                    } else {
                        if (solveBacktrack(board, box_ht, row_ht, col_ht, r, c + 1))
                            return true;
                    }
                    box[num - 1] = 0;
                    row[num - 1] = 0;
                    col[num - 1] = 0;
                }
                board[r][c] = '.';
            }
       } else {
            if (c == maxC - 1) {
                if (solveBacktrack(board, box_ht, row_ht, col_ht, r + 1, 0))
                    return true;
            } else {
                if (solveBacktrack(board, box_ht, row_ht, col_ht, r, c + 1))
                    return true;
            }
       }
    }
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int row_ht[boardSize][*boardColSize];
    int col_ht[boardSize][*boardColSize];
    int box_ht[boardSize][*boardColSize];
    int i, j, boxId;
    maxR = boardSize;
    maxC = *boardColSize;

        for (i = 0; i < boardSize; i++) {
            for (j = 0; j < *boardColSize; j++) {
                row_ht[i][j] = 0;
                col_ht[i][j] = 0;
                box_ht[i][j] = 0;
            }
        }
    
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            if (board[i][j] != '.') {
                row_ht[i][(board[i][j] - '0') - 1] = 1;
                col_ht[j][(board[i][j] - '0') - 1] = 1;
                boxId = getBoxId(i, j);
                box_ht[boxId][(board[i][j] - '0') - 1] = 1;
            }
        }
    }
    solveBacktrack(board, box_ht, row_ht, col_ht, 0, 0);
}

int main(int argc, char **argv)
{
    char *board[] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79",
    };
    solveSudoku(board, 9, NULL);
    return 0;
}