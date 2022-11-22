// Link: https://leetcode.com/problems/longest-palindromic-substring/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s){
    int len = strlen(s);
    if (len == 0) {
        return "";
    }
    int i = 0, j = 0, k = 0;
    int max = 1;
    int start = 0;
    int end = 0;
    int **dp = (int **)malloc(sizeof(int *) * len);
    for (i = 0; i < len; i++) {
        dp[i] = (int *)malloc(sizeof(int) * len);
        memset(dp[i], 0, sizeof(int) * len);
    }
    for (i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    for (i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            start = i;
            end = i + 1;
            max = 2;
        }
    }
    for (k = 3; k <= len; k++) {
        for (i = 0; i < len - k + 1; i++) {
            j = i + k - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                start = i;
                end = j;
                max = k;
            }
        }
    }
    char *result = (char *)malloc(sizeof(char) * (max + 1));
    memset(result, 0, sizeof(char) * (max + 1));
    for (i = 0; i < max; i++) {
        result[i] = s[start + i];
    }
    for (i = 0; i < len; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}

int main() {
    char *s = "babad";
    printf("%s", longestPalindrome(s));
    return 0;
}
