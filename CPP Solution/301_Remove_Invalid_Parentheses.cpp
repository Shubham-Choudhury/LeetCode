// Link: https://leetcode.com/problems/remove-invalid-parentheses/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;
        visited.insert(s);
        queue<string> q;
        q.push(s);
        bool found = false;
        while (!q.empty()) {
            string t = q.front();
            q.pop();
            if (isValid(t)) {
                res.push_back(t);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < t.size(); i++) {
                if (t[i] != '(' && t[i] != ')') continue;
                string str = t.substr(0, i) + t.substr(i + 1);
                if (visited.find(str) == visited.end()) {
                    q.push(str);
                    visited.insert(str);
                }
            }
        }
        return res;
    }
    
    bool isValid(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') cnt++;
            if (s[i] == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
};

int main() {
    string s = "()())()";
    Solution sol;
    vector<string> res = sol.removeInvalidParentheses(s);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}
