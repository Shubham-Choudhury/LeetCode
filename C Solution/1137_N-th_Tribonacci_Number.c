// Link: https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan&id=dynamic-programming-i

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int tribonacci(int n){
    int a = 0;
    int b = 1;
    int c = 1;
    int d = 0;
    for (int i = 0; i < n; i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return a;
}

int main() {
    int n = 4;
    printf("%d", tribonacci(n));
    return 0;
}