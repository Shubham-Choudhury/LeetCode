// Link: https://leetcode.com/problems/employee-importance/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, Employee *> m;
        for (auto e : employees)
            m[e->id] = e;
        int res = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            res += m[cur]->importance;
            for (auto sub : m[cur]->subordinates)
                q.push(sub);
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<Employee *> employees = {
        new Employee{1, 5, {2, 3}},
        new Employee{2, 3, {}},
        new Employee{3, 3, {}}};
    cout << obj.getImportance(employees, 1) << endl;
    return 0;
}