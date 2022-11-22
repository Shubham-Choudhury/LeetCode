// Link: https://leetcode.com/problems/regular-expression-matching/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char * s, char * p){
    int len_s = strlen(s);
    int len_p = strlen(p);
    if (len_p == 0) {
        return len_s == 0;
    }
    int i = 0, j = 0;
    int **dp = (int **)malloc(sizeof(int *) * (len_s + 1));
    for (i = 0; i < len_s + 1; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (len_p + 1));
        memset(dp[i], 0, sizeof(int) * (len_p + 1));
    }
    dp[0][0] = 1;
    for (i = 1; i < len_p + 1; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 2];
        }
    }
    for (i = 1; i < len_s + 1; i++) {
        for (j = 1; j < len_p + 1; j++) {
            if (p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 2];
                }
            } else {
                dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
            }
        }
    }
    bool result = dp[len_s][len_p];
    for (i = 0; i < len_s + 1; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}

int main() {
    char *s = "aa";
    char *p = "a*";
    printf("%d", isMatch(s, p));
    return 0;
}