// Link: https://leetcode.com/problems/bus-routes/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) {
            return 0;
        }
        int n = routes.size();
        vector<vector<int>> graph(n, vector<int>());
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < routes[i].size(); j++) {
                m[routes[i][j]].push_back(i);
            }
        }
        queue<int> q;
        vector<bool> visited(n, false);
        for(int i = 0; i < m[source].size(); i++) {
            q.push(m[source][i]);
            visited[m[source][i]] = true;
        }
        int time = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                for(int j = 0; j < routes[cur].size(); j++) {
                    if(routes[cur][j] == target) {
                        return time + 1;
                    }
                    for(int k = 0; k < m[routes[cur][j]].size(); k++) {
                        if(!visited[m[routes[cur][j]][k]]) {
                            q.push(m[routes[cur][j]][k]);
                            visited[m[routes[cur][j]][k]] = true;
                        }
                    }
                }
            }
            time++;
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1;
    int target = 6;
    Solution s;
    cout << s.numBusesToDestination(routes, source, target) << endl;
    return 0;
}