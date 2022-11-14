// Link: https://leetcode.com/problems/task-scheduler/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        if (len == 0)
            return 0;
        if (n == 0)
            return len;
        
        vector<int> count(26, 0);
        for (int i = 0; i < len; i++)
            count[tasks[i] - 'A']++;
        
        sort(count.begin(), count.end());
        int max_val = count[25] - 1;
        int idle_slots = max_val * n;
        
        for (int i = 24; i >= 0; i--) {
            idle_slots -= min(count[i], max_val);
        }
        
        return idle_slots > 0 ? idle_slots + len : len;
    }
};

int main() {
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << sol.leastInterval(tasks, n) << endl;
    return 0;
}