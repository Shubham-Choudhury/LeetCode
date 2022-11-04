// Link: https://leetcode.com/problems/keys-and-rooms/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, 0, visited);
        for(int i = 0; i < visited.size(); i++) {
            if(!visited[i]) {
                return false;
            }
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, int node, vector<bool>& visited) {
        visited[node] = true;
        for(int i = 0; i < rooms[node].size(); i++) {
            if(!visited[rooms[node][i]]) {
                dfs(rooms, rooms[node][i], visited);
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    cout << s.canVisitAllRooms(rooms) << endl;
    return 0;
}