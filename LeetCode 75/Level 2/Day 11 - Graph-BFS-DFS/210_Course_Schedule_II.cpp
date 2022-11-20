// Link: https://leetcode.com/problems/course-schedule-ii/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(degree[i] == 0)
                q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for(int i = 0; i < graph[cur].size(); i++){
                degree[graph[cur][i]]--;
                if(degree[graph[cur][i]] == 0)
                    q.push(graph[cur][i]);
            }
        }
        if(res.size() != numCourses)
            res.clear();
        return res;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    Solution s;
    vector<int> res = s.findOrder(numCourses, prerequisites);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}