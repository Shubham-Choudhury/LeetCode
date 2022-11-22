// Link: https://leetcode.com/problems/palindrome-number/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
    long long y = 0;
    int z = x;
    while (z != 0) {
        y = y * 10 + z % 10;
        z /= 10;
    }
    return x == y;
}

int main() {
    int x = 121;
    printf("%d", isPalindrome(x));
    return 0;
}