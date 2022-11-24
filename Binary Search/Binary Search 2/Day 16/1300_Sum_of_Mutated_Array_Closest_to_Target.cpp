// Link: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + arr[i - 1];
        int low = 0, high = arr[n - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int index = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int sum = prefix[index] + (n - index) * mid;
            if (sum <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        int sum1 = 0, sum2 = 0;
        int index = lower_bound(arr.begin(), arr.end(), high) - arr.begin();
        sum1 = prefix[index] + (n - index) * high;
        index = lower_bound(arr.begin(), arr.end(), low) - arr.begin();
        sum2 = prefix[index] + (n - index) * low;
        return abs(sum1 - target) <= abs(sum2 - target) ? high : low;
    }
};

int main() {
    Solution s;
    vector<int> arr = {4, 9, 3};
    cout << s.findBestValue(arr, 10);
    return 0;
}