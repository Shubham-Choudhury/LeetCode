// Link: https://leetcode.com/problems/as-far-from-land-as-possible/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    q.push({i, j});
        if(q.size() == 0 || q.size() == n * n)
            return -1;
        int res = -1;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x - 1 >= 0 && grid[x - 1][y] == 0){
                    grid[x - 1][y] = 1;
                    q.push({x - 1, y});
                }
                if(x + 1 < n && grid[x + 1][y] == 0){
                    grid[x + 1][y] = 1;
                    q.push({x + 1, y});
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 0){
                    grid[x][y - 1] = 1;
                    q.push({x, y - 1});
                }
                if(y + 1 < n && grid[x][y + 1] == 0){
                    grid[x][y + 1] = 1;
                    q.push({x, y + 1});
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    cout << s.maxDistance(grid) << endl;
    return 0;
}