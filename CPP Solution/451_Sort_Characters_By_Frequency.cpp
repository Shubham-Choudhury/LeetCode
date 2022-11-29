// Link: https://leetcode.com/problems/sort-characters-by-frequency/

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto c : s)
            mp[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto m : mp)
            pq.push({m.second, m.first});
        string res = "";
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            for (int i = 0; i < p.first; i++)
                res += p.second;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.frequencySort("tree");
    return 0;
}