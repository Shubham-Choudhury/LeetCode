// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if(len2 == 0)
        return 0;
    if(len1 == 0)
        return -1;
    int i = 0, j = 0;
    while(i < len1){
        if(haystack[i] == needle[j]){
            if(j == len2 - 1)
                return i - j;
            j++;
        }
        else{
            i = i - j;
            j = 0;
        }
        i++;
    }
    return -1;
}

int main() {
    char haystack[] = "hello";
    char needle[] = "ll";
    int result = strStr(haystack, needle);
    printf("%d", result);
    return 0;
}
