// Link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
    vector<int> res;
    void dfs(vector<vector<int>>& graph, vector<int>& indegree, int n, int cur) {
        if(cur < n) res.push_back(cur);
        indegree[cur] = -1; // mark it visited

        for(auto next : graph[cur]) {
            if(--indegree[next] == 0)
                dfs(graph, indegree, n, next);
        }
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // create graph with `n+m` nodes
        vector<vector<int>> graph(n + m);
        // create indegree with `n+m` nodes
        vector<int> indegree(n + m, 0);

        // Traverse through group elements
        for(int i = 0;i < group.size();i++) {
            // if `group[i] == -1` continue
            if(group[i] == -1) continue;
            graph[n+group[i]].push_back(i);
            indegree[i]++; // storing the indegree values
        }
        
        // Traverse through beforeItems
        for(int i = 0;i < beforeItems.size();i++) {
            for(int e : beforeItems[i]) {
                int a = group[e] == -1 ? e : n + group[e];
                int b = group[i] == -1 ? i : n + group[i];
                if(a == b) { // same group, ingroup order
                    graph[e].push_back(i);
                    indegree[i]++;
                } else { // outgoup order
                    graph[a].push_back(b);
                    indegree[b]++;
                }
            }
        }

        for(int i = 0;i < n + m;i++) {
            if(indegree[i] == 0)
                dfs(graph, indegree, n, i);
        }
        return res.size() == n ? res : vector<int>{};
    }
};

int main()
{
    Solution a;
    vector<int> group = {2, 0, -1, 3, 0};
    vector<vector<int>> beforeItems = {{2, 1, 3}, {2, 4}, {}, {}, {}};
    vector<int> res = a.sortItems(5, 5, group, beforeItems);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
