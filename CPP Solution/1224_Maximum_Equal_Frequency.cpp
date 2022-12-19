// Link: https://leetcode.com/problems/maximum-equal-frequency/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxEqualFreq(const vector<int>& nums) {
        unordered_map<int, int> c;
        unordered_map<int, unordered_set<int>> rc;
        for (int i : nums) ++c[i];
        for (auto& p : c) rc[p.second].insert(p.first);
        int n = nums.size();
        if (rcOK(rc)) return n;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int v = nums[i];
            int oldc = c[v];
            int newc = --c[v];
            rc[oldc].erase(v);
            if (rc[oldc].size() == 0) rc.erase(oldc);
            if (newc) rc[newc].insert(v);
            if (rcOK(rc)) return i;
        }
        return 0;
    }

    bool rcOK(unordered_map<int, unordered_set<int>>& rc) {
        if (rc.size() > 2) return false;
        if (rc.size() == 1) return rc.begin()->first == 1 || rc.begin()->second.size() == 1;
        pair<int, unordered_set<int>> p1 = *rc.begin();
        pair<int, unordered_set<int>> p2 = *next(rc.begin());
        if (p1.first > p2.first) swap(p1, p2);
        if (p1.first == 1 && p1.second.size() == 1) return true;
        if (p2.first - p1.first != 1) return false;
        return p2.second.size() == 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,1,1,2,2,2,3,3,3,4,4,4,5};
    cout << s.maxEqualFreq(nums) << endl;
    return 0;
}
