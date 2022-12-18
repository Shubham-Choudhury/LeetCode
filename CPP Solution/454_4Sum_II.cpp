// Link: https://leetcode.com/problems/4sum-ii/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                m[A[i] + B[j]]++;
            }
        }
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                ans += m[-(C[i] + D[j])];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    cout << s.fourSumCount(A, B, C, D) << endl;
    return 0;
}
