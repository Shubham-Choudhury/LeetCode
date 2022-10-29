// Link: https://leetcode.com/problems/climbing-stairs/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
using namespace std;


class solution {
public:
    int climbstairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int a = 1;
        int b = 2;
        int c = 0;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    solution s;
    cout << s.climbstairs(1) << endl;
    cout << s.climbstairs(2) << endl;
    cout << s.climbstairs(3) << endl;
    cout << s.climbstairs(4) << endl;
    cout << s.climbstairs(5) << endl;
    cout << s.climbstairs(6) << endl;
}