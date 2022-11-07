// Link: https://leetcode.com/problems/letter-case-permutation/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        helper(res, S, 0);
        return res;
    }
    
    void helper(vector<string>& res, string S, int start) {
        if (start == S.size()) {
            res.push_back(S);
            return;
        }
        if (isalpha(S[start])) {
            S[start] = tolower(S[start]);
            helper(res, S, start + 1);
            S[start] = toupper(S[start]);
            helper(res, S, start + 1);
        }
        else {
            helper(res, S, start + 1);
        }
    }
};

int main()
{
    Solution sol;
    string S = "a1b2";
    vector<string> res = sol.letterCasePermutation(S);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}