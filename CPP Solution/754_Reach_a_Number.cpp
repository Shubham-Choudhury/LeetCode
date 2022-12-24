// Link: https://leetcode.com/problems/reach-a-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target > 0) {
            target -= ++k;
        }
        return target % 2 == 0 ? k : k + 1 + k % 2;
    }
};

int main()
{
    Solution sol;
    int target;
    int ans;

    // Output: 2
    target = 3;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 3
    target = 2;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 3
    target = 4;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 4
    target = 5;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 5
    target = 6;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 5
    target = 7;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 6
    target = 8;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 6
    target = 9;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 7
    target = 10;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 7
    target = 11;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 8
    target = 12;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 8
    target = 13;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 9
    target = 14;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    // Output: 9
    target = 15;
    ans = sol.reachNumber(target);
    cout << ans << endl;

    return 0;

}