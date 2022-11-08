// Link: https://leetcode.com/problems/jump-game-iii/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (arr[u] == 0) {
                return true;
            }
            int v1 = u + arr[u];
            int v2 = u - arr[u];
            if (v1 >= 0 && v1 < n && !visited[v1]) {
                q.push(v1);
                visited[v1] = true;
            }
            if (v2 >= 0 && v2 < n && !visited[v2]) {
                q.push(v2);
                visited[v2] = true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    int start = 5;
    cout << sol.canReach(arr, start) << endl;
    return 0;
}