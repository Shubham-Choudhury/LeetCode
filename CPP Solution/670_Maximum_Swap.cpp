// Link: https://leetcode.com/problems/maximum-swap/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > s[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};

int main(void) {
    Solution sol;
    int num = 2736;
    int res = sol.maximumSwap(num);
    cout << res << endl;
    return 0;
}
