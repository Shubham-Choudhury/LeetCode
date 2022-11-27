// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** letterCombinations(char * digits, int* returnSize){
    int n = strlen(digits);
    if(n == 0){
        *returnSize = 0;
        return NULL;
    }
    char *map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int *count = (int*)malloc(sizeof(int) * n);
    int *index = (int*)malloc(sizeof(int) * n);
    int i, j, k;
    for(i = 0; i < n; i++){
        count[i] = strlen(map[digits[i] - '2']);
        index[i] = 0;
    }
    char **ans = (char**)malloc(sizeof(char*) * 10000);
    for(i = 0; i < 10000; i++)
        ans[i] = (char*)malloc(sizeof(char) * (n+1));
    i = 0;
    while(1){
        for(j = 0; j < n; j++)
            ans[i][j] = map[digits[j] - '2'][index[j]];
        ans[i][j] = '\0';
        i++;
        for(j = n-1; j >= 0; j--){
            if(index[j] < count[j] - 1){
                index[j]++;
                break;
            }
            else
                index[j] = 0;
        }
        if(j == -1)
            break;
    }
    *returnSize = i;
    return ans;
}

int main() {
    char digits[] = "23";
    int returnSize;
    char **result = letterCombinations(digits, &returnSize);
    for(int i = 0; i < returnSize; i++)
        printf("%s", result[i]);
    return 0;
}
