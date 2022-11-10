// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n, 0);
        for (auto& e : edges) {
            in[e[1]]++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    vector<int> res = obj.findSmallestSetOfVertices(6, edges);
    for (auto& r : res) {
        cout << r << " ";
    }
    return 0;
}