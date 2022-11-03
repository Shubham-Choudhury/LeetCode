// Link: https://leetcode.com/problems/best-sightseeing-pair/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0, mx = A[0] + 0;
        for (int j = 1; j < A.size(); j++) {
            res = max(res, mx + A[j] - j);
            mx = max(mx, A[j] + j);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> A = {8, 1, 5, 2, 6};
    int res = s.maxScoreSightseeingPair(A);
    return 0;
}