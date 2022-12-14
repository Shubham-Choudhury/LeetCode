// Link: https://leetcode.com/problems/swim-in-rising-water/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int n;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(int x, int y, vector<vector<int>> &arr,
             int &timer, vector<vector<bool>> &visited)
    {

        if (x == n - 1 && y == n - 1)
            return true;

        if (arr[x][y] > timer)
            return false;

        visited[x][y] = true;
        bool res = false;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] <= timer)
            {

                res = res || dfs(nx, ny, arr, timer, visited);
            }
        }
        return res;
    }

    int swimInWater(vector<vector<int>> &arr)
    {

        n = arr.size();
        int timer = max(arr[0][0], arr[n - 1][n - 1]);

        int lo = arr[0][0];
        int hi = n * n;
        int ans = 0;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            vector<vector<bool>> visited(n, vector<bool>(n, false));

            if (dfs(0, 0, arr, mid, visited))
            {

                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    Solution obj;
    cout << obj.swimInWater(grid) << endl;
    return 0;
}
