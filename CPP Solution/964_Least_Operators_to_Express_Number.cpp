// Link: https://leetcode.com/problems/least-operators-to-express-number/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
        int leastOpsExpressTarget(int x, int y) {
        int pos = 0, neg = 0, k, pos2, neg2, cur;
        for (k = 0; y > 0; ++k, y /= x) {
            cur = y % x;
            if (k > 0) {
                pos2 = min(cur * k + pos, (cur + 1) * k + neg);
                neg2 = min((x - cur) * k + pos, (x - cur - 1) * k + neg);
                pos = pos2, neg = neg2;
            } else {
                pos = cur * 2;
                neg = (x - cur) * 2;
            }
        }
        return min(pos, k + neg) - 1;
    }
};

int main() {
    Solution sol;
    int x = 3;
    int target = 19;
    cout << sol.leastOpsExpressTarget(x, target) << endl;
    return 0;
}
