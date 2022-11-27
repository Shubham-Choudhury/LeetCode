// Link: https://leetcode.com/problems/generate-parentheses/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generateParenthesisHelper(char **ans, int *i, char *str, int left, int right, int index){
    if(left == 0 && right == 0){
        strcpy(ans[*i], str);
        (*i)++;
        return 0;
    }
    if(left > 0){
        str[index] = '(';
        generateParenthesisHelper(ans, i, str, left-1, right, index+1);
    }
    if(right > left){
        str[index] = ')';
        generateParenthesisHelper(ans, i, str, left, right-1, index+1);
    }
    return 0;
}

char ** generateParenthesis(int n, int* returnSize){
    char **ans = (char**)malloc(sizeof(char*) * 10000);
    for(int i = 0; i < 10000; i++)
        ans[i] = (char*)malloc(sizeof(char) * (2*n+1));
    int i = 0;
    int left = n, right = n;
    char *str = (char*)malloc(sizeof(char) * (2*n+1));
    str[2*n] = '\0';
    generateParenthesisHelper(ans, &i, str, left, right, 0);
    *returnSize = i;
    return ans;
}



int main() {
    int n = 3;
    int returnSize;
    char **result = generateParenthesis(n, &returnSize);
    for(int i = 0; i < returnSize; i++)
        printf("%s", result[i]);
    return 0;
}
