// Link: https://leetcode.com/problems/reconstruct-itinerary/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto ticket : tickets)
            graph[ticket[0]].insert(ticket[1]);
        vector<string> res;
        stack<string> stk;
        stk.push("JFK");
        while (!stk.empty()) {
            string top = stk.top();
            if (graph[top].empty()) {
                res.push_back(top);
                stk.pop();
            } else {
                stk.push(*graph[top].begin());
                graph[top].erase(graph[top].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> tickets;
    vector<string> res;
    
    // Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
    tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    res = sol.findItinerary(tickets);
    for (auto s : res)
        cout << s << " ";
    cout << endl;
    
    // Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
    tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    res = sol.findItinerary(tickets);
    for (auto s : res)
        cout << s << " ";
    cout << endl;
    
    // Output: ["JFK","NRT","JFK","KUL"]
    tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    res = sol.findItinerary(tickets);
    for (auto s : res)
        cout << s << " ";
    cout << endl;
    
    return 0;
}

