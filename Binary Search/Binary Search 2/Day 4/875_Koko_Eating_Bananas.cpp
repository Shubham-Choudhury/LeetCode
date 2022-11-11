// Link: https://leetcode.com/problems/koko-eating-bananas/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1e9;
        while (l < r) {
            int m = l + (r - l) / 2;
            int h = 0;
            for (int p : piles) {
                h += (p + m - 1) / m;
            }
            if (h > H) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};

int main() {
    Solution s;
    vector<int> piles = {3, 6, 7, 11};
    int H = 8;
    cout << s.minEatingSpeed(piles, H) << endl;
    return 0;
}