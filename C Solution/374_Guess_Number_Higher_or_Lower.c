// Link: https://leetcode.com/problems/guess-number-higher-or-lower/?envType=study-plan&id=binary-search-i

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int guess(int num);

int guessNumber(int n){
    int left = 1;
    int right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = guess(mid);
        if (res == 0) {
            return mid;
        } else if (res == -1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n = 10;
    printf("%d", guessNumber(n));
    return 0;
}