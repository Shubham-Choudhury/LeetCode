// Link: https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
        int numTimesAllBlue(vector<int>& A) {
        int right = 0, res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            res += (right = max(right, A[i])) == i + 1;
        return res;
    }
};


int main(){
    Solution sol;
    vector<int> A = {2,1,3,5,4};
    cout << sol.numTimesAllBlue(A) << endl;
    return 0;
}