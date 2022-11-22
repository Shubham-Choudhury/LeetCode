// Link: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& A) {
        int N = A.size(), left = 0, right = N - 1;
        while (left + 1 < N && A[left] <= A[left + 1]) ++left;
        if (left == A.size() - 1) return 0;
        while (right > left && A[right - 1] <= A[right]) --right;
        int ans = min(N - left - 1, right), i = 0, j = right;
        while (i <= left && j < N) {
            if (A[j] >= A[i]) {
                ans = min(ans, j - i - 1);
                ++i;
            } else ++j;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
    cout << s.findLengthOfShortestSubarray(arr) << endl;
    return 0;
}