// Link: https://leetcode.com/problems/brick-wall/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (auto& row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; ++i) {
                sum += row[i];
                cnt[sum]++;
            }
        }
        int max_cnt = 0;
        for (auto& it : cnt) {
            max_cnt = max(max_cnt, it.second);
        }
        return wall.size() - max_cnt;
    }
};

int main() {
    vector<vector<int>> wall = {
        {1, 2, 2, 1},
        {3, 1, 2},
        {1, 3, 2},
        {2, 4},
        {3, 1, 2},
        {1, 3, 1, 1}
    };
    Solution sol;
    cout << sol.leastBricks(wall) << endl;
    return 0;
}
