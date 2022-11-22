// Link: https://leetcode.com/problems/longest-common-prefix/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    }
    int i = 0, j = 0;
    int len = strlen(strs[0]);
    for (i = 1; i < strsSize; i++) {
        if (strlen(strs[i]) < len) {
            len = strlen(strs[i]);
        }
    }
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    memset(result, 0, sizeof(char) * (len + 1));
    for (i = 0; i < len; i++) {
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                return result;
            }
        }
        result[i] = strs[0][i];
    }
    return result;
}

int main() {
    char *strs[] = {"flower", "flow", "flight"};
    printf("%s", longestCommonPrefix(strs, 3));
    return 0;
}

