// Link: https://leetcode.com/problems/fibonacci-number/?envType=study-plan&id=dynamic-programming-i

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int fib(int N){
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = 0; i < N; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int N = 4;
    printf("%d", fib(N));
    return 0;
}