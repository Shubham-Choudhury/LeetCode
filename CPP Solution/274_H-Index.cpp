// Link: https://leetcode.com/problems/h-index/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n) {
                ++buckets[n];
            } else {
                ++buckets[citations[i]];
            }
        }
        int count = 0;
        for (int i = n; i >= 0; --i) {
            count += buckets[i];
            if (count >= i) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << Solution().hIndex(citations);
    return 0;
}
