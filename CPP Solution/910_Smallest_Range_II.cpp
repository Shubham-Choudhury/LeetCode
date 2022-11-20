// Link: https://leetcode.com/problems/smallest-range-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int result = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; i++) {
            int a = A[i];
            int b = A[i + 1];
            int high = max(A[n - 1] - K, a + K);
            int low = min(A[0] + K, b - K);
            result = min(result, high - low);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {1};
    int K = 0;
    cout << s.smallestRangeII(A, K) << endl;
    return 0;
}