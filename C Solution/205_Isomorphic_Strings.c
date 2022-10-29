// Link: https://leetcode.com/problems/isomorphic-strings/?envType=study-plan&id=level-1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isIsomorphic(char * s, char * t){
    int len = strlen(s);
    int map[256] = {0};
    int map2[256] = {0};
    for (int i = 0; i < len; i++) {
        if (map[s[i]] != map2[t[i]]) {
            return false;
        }
        map[s[i]] = i + 1;
        map2[t[i]] = i + 1;
    }
    return true;
}

int main() {
    char *s = "egg";
    char *t = "add";
    printf("%d", isIsomorphic(s, t));
    return 0;
}