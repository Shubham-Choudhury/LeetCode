// Link: https://leetcode.com/problems/roman-to-integer/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int romanToInt(char * s){
    int len = strlen(s);
    int i = 0;
    int result = 0;
    for (i = 0; i < len; i++) {
        switch (s[i]) {
            case 'I':
                if (i < len - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    result -= 1;
                } else {
                    result += 1;
                }
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if (i < len - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    result -= 10;
                } else {
                    result += 10;
                }
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if (i < len - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    result -= 100;
                } else {
                    result += 100;
                }
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                break;
        }
    }
    return result;
}

int main() {
    char *s = "MCMXCIV";
    printf("%d", romanToInt(s));
    return 0;
}