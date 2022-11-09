// Link: https://leetcode.com/problems/open-the-lock/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000")) return -1;
        queue<string> q({"0000"});
        for (int steps = 0; !q.empty(); ++steps) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front(); q.pop();
                if (curr == target) return steps;
                for (auto nei : neighbors(curr)) {
                    if (deadSet.count(nei)) continue;
                    deadSet.insert(nei); // Marked as visited
                    q.push(nei);
                }
            }
        }
        return -1;
    }
    vector<string> neighbors(const string& code) {
        vector<string> result;
        for (int i = 0; i < 4; i++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                result.push_back(nei);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    cout << s.openLock(deadends, "0202") << endl;
    return 0;
}