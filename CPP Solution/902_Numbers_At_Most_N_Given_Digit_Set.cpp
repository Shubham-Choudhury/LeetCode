// Link: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string s = to_string(N);
        int n = s.size();
        int res = 0;
        for (int i = 1; i < n; i++) {
            res += pow(D.size(), i);
        }
        for (int i = 0; i < n; i++) {
            bool hasSame = false;
            for (string d : D) {
                if (d[0] < s[i]) {
                    res += pow(D.size(), n - i - 1);
                } else if (d[0] == s[i]) {
                    hasSame = true;
                }
            }
            if (!hasSame) {
                return res;
            }
        }
        return res + 1;
    }
};

int main()
{
    Solution sol;
    vector<string> D;
    int N;

    // Output: 20
    D = {"1", "3", "5", "7"}, N = 100;
    cout << sol.atMostNGivenDigitSet(D, N) << endl;

    // Output: 29523
    D = {"1", "4", "9"}, N = 1000000000;
    cout << sol.atMostNGivenDigitSet(D, N) << endl;

    return 0;
}