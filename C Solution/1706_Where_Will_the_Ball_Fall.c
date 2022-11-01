// Link: https://leetcode.com/problems/where-will-the-ball-fall/submissions/

#include <stdio.h>
#include <stdlib.h>


int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize){
    int *result = (int*)malloc(sizeof(int) * gridSize);
    *returnSize = gridSize;
    
    for (int i = 0; i < gridSize; i++) {
        int col = 0;
        for (int j = 0; j < gridSize; j++) {
            if (grid[j][col] == 1) {
                if (col + 1 < gridSize && grid[j][col + 1] == 1) {
                    col++;
                } else {
                    col = -1;
                    break;
                }
            } else {
                if (col - 1 >= 0 && grid[j][col - 1] == -1) {
                    col--;
                } else {
                    col = -1;
                    break;
                }
            }
        }
        result[i] = col;
    }
    
    return result;
}

int main() {
    int **grid = (int**)malloc(sizeof(int*) * 2);
    grid[0] = (int*)malloc(sizeof(int) * 4);
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[0][2] = 1;
    grid[0][3] = -1;
    grid[1] = (int*)malloc(sizeof(int) * 4);
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[1][2] = -1;
    grid[1][3] = -1;
    
    int returnSize;
    int *result = findBall(grid, 2, NULL, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}