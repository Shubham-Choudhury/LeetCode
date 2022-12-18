// Link: https://leetcode.com/problems/rotate-function/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int L = A.size();
        if (L == 0) {
            return 0;
        }
        int sum = 0;
        int F = 0;
        for (int i = 0; i < L; i++) {
            sum += A[i];
            F += i * A[i];
        }
        int maxF = F;
        for (int i = 1; i < L; i++) {
            F = F + sum - L * A[L - i];
            maxF = max(maxF, F);
        }
        return maxF;
    }
};

int main()
{
    Solution s;
    vector<int> A = {4, 3, 2, 6};
    cout << s.maxRotateFunction(A) << endl;
    return 0;
}
