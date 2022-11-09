// Link: https://leetcode.com/problems/monotonic-array/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n == 1) {
            return true;
        }
        int i = 0;
        while (i < n - 1 && A[i] == A[i + 1]) {
            i++;
        }
        if (i == n - 1) {
            return true;
        }
        bool increasing = A[i] < A[i + 1];
        for (int j = i + 1; j < n - 1; j++) {
            if (increasing && A[j] > A[j + 1]) {
                return false;
            }
            if (!increasing && A[j] < A[j + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 2, 2, 3};
    cout << sol.isMonotonic(A) << endl;
    return 0;
}