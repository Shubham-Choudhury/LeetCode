// Link: https://leetcode.com/problems/super-washing-machines/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = (int) machines.size();
        vector<int> sum(len + 1);
        for (int i = 0; i < len; ++ i)
            sum[i + 1] = sum[i] + machines[i];
        if (sum[len] % len != 0)
            return -1;
        int avg = sum[len] / len;
        int ret = 0;
        for (int i = 0; i < len; ++ i) {
            int l = i * avg - sum[i];
            int r = (len - i - 1) * avg - (sum[len] - sum[i + 1]);
            if (l > 0 && r > 0)
                ret = max(ret, l + r);
            else
                ret = max(ret, max(abs(l), abs(r)));
        }
        return ret;
    }
};

int main() {
    vector<int> machines = {1, 0, 5};
    Solution sol;
    cout << sol.findMinMoves(machines) << endl;

    return 0;
}
