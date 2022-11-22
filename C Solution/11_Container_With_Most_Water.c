// Link: https://leetcode.com/problems/container-with-most-water/

#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize){
    int i = 0, j = heightSize - 1;
    int max = 0;
    while (i < j) {
        int area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
        if (area > max) {
            max = area;
        }
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return max;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d", maxArea(height, sizeof(height) / sizeof(int)));
    return 0;
}