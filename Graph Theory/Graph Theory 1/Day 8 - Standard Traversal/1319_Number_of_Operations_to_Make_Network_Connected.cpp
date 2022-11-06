// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto& connection : connections) {
            int x = find(parent, connection[0]);
            int y = find(parent, connection[1]);
            if (x != y) {
                parent[x] = y;
                n--;
            }
        }
        return n - 1;
    }
    
    int find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }
};

int main() {
    Solution s;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    cout << s.makeConnected(4, connections) << endl;
    return 0;
}