// Link: https://leetcode.com/problems/minimum-genetic-mutation/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(end) == bankSet.end())
            return -1;
        
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                
                if (curr == end)
                    return level;
                
                for (int j = 0; j < curr.size(); j++) {
                    char old = curr[j];
                    for (char c : "ACGT") {
                        curr[j] = c;
                        if (bankSet.find(curr) != bankSet.end() && visited.find(curr) == visited.end()) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[j] = old;
                }
            }
            level++;
        }
        
        return -1;
    }
};

int main()
{
    Solution s;
    vector<string> bank = {"AACCGGTA"};
    cout << s.minMutation("AACCGGTT", "AACCGGTA", bank) << endl;
    return 0;
}