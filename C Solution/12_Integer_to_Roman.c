// Link: https://leetcode.com/problems/integer-to-roman/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * intToRoman(int num){
    char *result = (char *)malloc(sizeof(char) * 16);
    memset(result, 0, sizeof(char) * 16);
    int i = 0;
    while (num != 0) {
        if (num >= 1000) {
            result[i++] = 'M';
            num -= 1000;
        } else if (num >= 900) {
            result[i++] = 'C';
            result[i++] = 'M';
            num -= 900;
        } else if (num >= 500) {
            result[i++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            result[i++] = 'C';
            result[i++] = 'D';
            num -= 400;
        } else if (num >= 100) {
            result[i++] = 'C';
            num -= 100;
        } else if (num >= 90) {
            result[i++] = 'X';
            result[i++] = 'C';
            num -= 90;
        } else if (num >= 50) {
            result[i++] = 'L';
            num -= 50;
        } else if (num >= 40) {
            result[i++] = 'X';
            result[i++] = 'L';
            num -= 40;
        } else if (num >= 10) {
            result[i++] = 'X';
            num -= 10;
        } else if (num >= 9) {
            result[i++] = 'I';
            result[i++] = 'X';
            num -= 9;
        } else if (num >= 5) {
            result[i++] = 'V';
            num -= 5;
        } else if (num >= 4) {
            result[i++] = 'I';
            result[i++] = 'V';
            num -= 4;
        } else {
            result[i++] = 'I';
            num -= 1;
        }
    }
    return result;
}

int main() {
    int num = 1994;
    printf("%s", intToRoman(num));
    return 0;
}
