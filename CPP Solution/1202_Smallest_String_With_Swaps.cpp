// Link: https://leetcode.com/problems/smallest-string-with-swaps/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (auto& p : pairs) {
            int x = find(parent, p[0]);
            int y = find(parent, p[1]);
            if (x != y)
                parent[x] = y;
        }
        
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int x = find(parent, i);
            groups[x].push_back(i);
        }
        
        for (auto& g : groups) {
            vector<char> chars;
            for (int i : g.second)
                chars.push_back(s[i]);
            sort(chars.begin(), chars.end());
            sort(g.second.begin(), g.second.end());
            for (int i = 0; i < g.second.size(); i++)
                s[g.second[i]] = chars[i];
        }
        
        return s;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]);
        return parent[x];
    }
};

int main(){
    Solution s;
    vector<vector<int>> pairs = {{0,3},{1,2},{0,2}};
    string str = "dcab";
    cout << s.smallestStringWithSwaps(str, pairs) << endl;
    return 0;

}