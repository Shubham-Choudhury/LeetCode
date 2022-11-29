// Link: https://leetcode.com/problems/keys-and-rooms/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int i) {
        visited[i] = true;
        for (auto j : rooms[i]) {
            if (!visited[j])
                dfs(rooms, visited, j);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for (auto v : visited) {
            if (!v)
                return false;
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    cout << obj.canVisitAllRooms(rooms);
    return 0;
}