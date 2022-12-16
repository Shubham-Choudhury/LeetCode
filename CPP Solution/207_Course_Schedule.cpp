// Link: https://leetcode.com/problems/course-schedule/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto &a : prerequisites)
        {
            graph[a[1]].push_back(a[0]);
            indegree[a[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto &a : graph[t])
            {
                indegree[a]--;
                if (indegree[a] == 0)
                    q.push(a);
            }
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << a.canFinish(2, prerequisites) << endl;
    prerequisites = {{1, 0}, {0, 1}};
    cout << a.canFinish(2, prerequisites) << endl;
    return 0;
}
