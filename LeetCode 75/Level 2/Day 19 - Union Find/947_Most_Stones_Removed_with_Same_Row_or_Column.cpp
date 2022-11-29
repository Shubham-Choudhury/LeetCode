// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int p1 = find(parent, i);
                    int p2 = find(parent, j);
                    if (p1 != p2)
                        parent[p1] = p2;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                count++;
        }
        
        return n - count;
    }
    
    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
};

int main() {
    Solution obj;
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << obj.removeStones(stones);
    return 0;
}