// Link: https://leetcode.com/problems/first-bad-version/?envType=study-plan&id=algorithm-i

#include <iostream>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool isBadVersion(int version) {
        return version >= 4;
    }
};



int main() {
    Solution s;
    cout << s.firstBadVersion(1) << endl;
    return 0;
}