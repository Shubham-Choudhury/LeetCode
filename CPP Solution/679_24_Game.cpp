// Link: https://leetcode.com/problems/24-game/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
        }
        return solve(v);
    }
    
    bool solve(vector<double> v) {
        if (v.size() == 1) {
            return abs(v[0] - 24) < 1e-6;
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (i != j) {
                    vector<double> next;
                    for (int k = 0; k < v.size(); k++) {
                        if (k != i && k != j) {
                            next.push_back(v[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k < 2 && j > i) continue;
                        if (k == 0) next.push_back(v[i] + v[j]);
                        if (k == 1) next.push_back(v[i] * v[j]);
                        if (k == 2) next.push_back(v[i] - v[j]);
                        if (k == 3) {
                            if (v[j] != 0) {
                                next.push_back(v[i] / v[j]);
                            } else {
                                continue;
                            }
                        }
                        if (solve(next)) return true;
                        next.pop_back();
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 1, 8, 7};
    cout << sol.judgePoint24(nums) << endl;
    return 0;
}
