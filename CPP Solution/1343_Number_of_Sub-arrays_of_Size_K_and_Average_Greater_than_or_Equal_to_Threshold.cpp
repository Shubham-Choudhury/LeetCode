// Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int ans = 0;
        if (sum / k >= threshold) {
            ans++;
        }
        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];
            if (sum / k >= threshold) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;
    cout << sol.numOfSubarrays(arr, k, threshold) << endl;
    return 0;
}
