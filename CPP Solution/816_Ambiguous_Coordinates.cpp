// Link: https://leetcode.com/problems/ambiguous-coordinates/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        for (int i = 2; i < S.size() - 1; ++i) {
            vector<string> A = f(S.substr(1, i - 1)), B = f(S.substr(i, S.size() - i - 1));
            for (string a : A) {
                for (string b : B) {
                    res.push_back("(" + a + ", " + b + ")");
                }
            }
        }
        return res;
    }
    
    vector<string> f(string S) {
        int n = S.size();
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            string left = S.substr(0, i), right = S.substr(i);
            if ((left.size() == 1 || left[0] != '0' || left == "0") && right.back() != '0') {
                res.push_back(left + (i == n ? "" : ".") + right);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string S = "(123)";
    vector<string> res = s.ambiguousCoordinates(S);
    for (string str : res) {
        cout << str << endl;
    }
    return 0;
}
