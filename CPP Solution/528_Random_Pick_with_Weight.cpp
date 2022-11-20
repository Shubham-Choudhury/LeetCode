// Link: https://leetcode.com/problems/random-pick-with-weight/

#include <iostream>
#include <vector>
#include <numeric>
#include <random>
using namespace std;

class Solution {
public:
    vector<int> prefixSum;
    int totalSum;
    Solution(vector<int>& w) {
        prefixSum.resize(w.size());
        prefixSum[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + w[i];
        }
        totalSum = prefixSum.back();
    }
    
    int pickIndex() {
        int target = rand() % totalSum + 1;
        int low = 0, high = prefixSum.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (prefixSum[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    vector<int> w = {1, 3};
    Solution s(w);
    cout << s.pickIndex() << endl;
    return 0;
}