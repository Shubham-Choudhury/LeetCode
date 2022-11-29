// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> in(n, 0);
        for (auto e : edges)
            in[e[1]]++;
        for (int i = 0; i < n; i++)
            if (in[i] == 0)
                res.push_back(i);
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    vector<int> res = s.findSmallestSetOfVertices(6, edges);
    for (auto i : res)
        cout << i << " ";
    return 0;
}