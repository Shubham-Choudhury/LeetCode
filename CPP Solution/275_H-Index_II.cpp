// Link: https://leetcode.com/problems/h-index-ii/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] == n - mid) {
                return n - mid;
            } else if (citations[mid] < n - mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return n - left;
    }
};

int main() {
    Solution s;
    vector<int> citations = {0, 1, 3, 5, 6};
    cout << s.hIndex(citations) << endl;
    return 0;
}