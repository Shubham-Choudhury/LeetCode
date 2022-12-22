// Link: https://leetcode.com/problems/reducing-dishes/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int res = 0;
        int sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += satisfaction[i];
            if (sum > 0) {
                res += sum;
            } else {
                break;
            }
        }
        return res;
    }
};

int main(void) {
    Solution sol;
    vector<int> satisfaction = {-1,-8,0,5,-9};
    int res = sol.maxSatisfaction(satisfaction);
    cout << res << endl;
    return 0;
}
