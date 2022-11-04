// Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] < 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout << s.countNegatives(grid) << endl;
    return 0;
}