// Link: https://leetcode.com/problems/is-subsequence/?envType=study-plan&id=level-1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char * s, char * t){
    int len = strlen(s);
    int len2 = strlen(t);
    int i = 0;
    int j = 0;
    while (i < len && j < len2) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == len;
}

int main() {
    char *s = "abc";
    char *t = "ahbgdc";
    printf("%d", isSubsequence(s, t));
    return 0;
}