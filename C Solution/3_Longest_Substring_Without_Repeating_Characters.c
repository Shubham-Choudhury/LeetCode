// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int i, j, k, max = 0;
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            for (k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    break;
                }
            }
            if (k != j) {
                break;
            }
        }
        if (j - i > max) {
            max = j - i;
        }
    }
    return max;
}

int main(){
    char s[]  = "pwwkew";
    printf("%d", lengthOfLongestSubstring(s));

    return 0;
}