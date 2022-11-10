// Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/?envType=study-plan&id=binary-search-ii

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9;
        while (l < r) {
            int m = l + (r - l) / 2;
            int ops = 0;
            for (int x : nums) {
                ops += (x - 1) / m;
            }
            if (ops <= maxOperations) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {9};
    int maxOperations = 2;
    cout << sol.minimumSize(nums, maxOperations) << endl;
    return 0;
}