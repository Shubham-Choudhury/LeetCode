// Link: https://leetcode.com/problems/closest-divisors/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans;
        int a = num + 1;
        int b = num + 2;
        int diff = INT_MAX;
        for (int i = 1; i <= sqrt(a); i++) {
            if (a % i == 0) {
                int j = a / i;
                if (abs(i - j) < diff) {
                    diff = abs(i - j);
                    ans = {i, j};
                }
            }
        }
        for (int i = 1; i <= sqrt(b); i++) {
            if (b % i == 0) {
                int j = b / i;
                if (abs(i - j) < diff) {
                    diff = abs(i - j);
                    ans = {i, j};
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> ans = sol.closestDivisors(123);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
    
}