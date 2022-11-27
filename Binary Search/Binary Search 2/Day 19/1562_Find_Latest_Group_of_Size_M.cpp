// Link: https://leetcode.com/problems/find-latest-group-of-size-m/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> groups(n + 2, 0);
        vector<int> sizes(n + 1, 0);
        int result = -1;
        for (int i = 0; i < n; i++) {
            int index = arr[i];
            int left = groups[index - 1];
            int right = groups[index + 1];
            int size = left + right + 1;
            groups[index - left] = size;
            groups[index + right] = size;
            sizes[left]--;
            sizes[right]--;
            sizes[size]++;
            if (sizes[m] > 0) {
                result = i + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 5, 1, 2, 4};
    int m = 1;
    cout << solution.findLatestStep(arr, m) << endl;
    return 0;
}