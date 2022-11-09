// Link: https://leetcode.com/problems/maximal-network-rank/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        
        for (const auto& road: roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        int maximal = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int network_rank = graph[i].size() + graph[j].size();
                
                if (graph[j].count(i)) {
                    --network_rank;
                }
                
                maximal = max(maximal, network_rank);
            }
            
        }
        return maximal;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> roads;
    int result;
    
    roads = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    result = sol.maximalNetworkRank(5, roads);
    cout << result << endl;
    
    roads = {{0,1},{0,3},{1,2},{1,3},{2,3}};
    result = sol.maximalNetworkRank(4, roads);
    cout << result << endl;
    
    roads = {{0,1}};
    result = sol.maximalNetworkRank(2, roads);
    cout << result << endl;
    
    return 0;
}