// Link: https://leetcode.com/problems/exclusive-time-of-functions/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> s;
        int prev_time = 0;
        for (string log : logs) {
            int pos1 = log.find(":");
            int pos2 = log.find(":", pos1 + 1);
            int id = stoi(log.substr(0, pos1));
            string status = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int time = stoi(log.substr(pos2 + 1));
            if (status == "start") {
                if (!s.empty()) {
                    res[s.top()] += time - prev_time;
                }
                s.push(id);
                prev_time = time;
            } else {
                res[s.top()] += time - prev_time + 1;
                s.pop();
                prev_time = time + 1;
            }
        }
        return res;
    }
};

int main(void) {
    Solution sol;
    int n = 2;
    vector<string> logs = {
        "0:start:0",
        "1:start:2",
        "1:end:5",
        "0:end:6"
    };
    vector<int> res = sol.exclusiveTime(n, logs);
    for (auto& time : res) {
        cout << time << " ";
    }
    cout << endl;
    return 0;
}
