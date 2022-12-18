// Link: https://leetcode.com/problems/evaluate-division/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        vector<double> result;
        for (int i = 0; i < queries.size(); i++)
        {
            unordered_set<string> visited;
            result.push_back(calcEquationRec(graph, queries[i][0], queries[i][1], visited));
        }
        return result;
    }

private:
    double calcEquationRec(unordered_map<string, unordered_map<string, double>> &graph, string start, string end, unordered_set<string> &visited)
    {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            return -1;
        if (graph[start].find(end) != graph[start].end())
            return graph[start][end];
        visited.insert(start);
        for (auto it = graph[start].begin(); it != graph[start].end(); it++)
        {
            if (visited.find(it->first) == visited.end())
            {
                double temp = calcEquationRec(graph, it->first, end, visited);
                if (temp != -1)
                    return it->second * temp;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> result = s.calcEquation(equations, values, queries);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
