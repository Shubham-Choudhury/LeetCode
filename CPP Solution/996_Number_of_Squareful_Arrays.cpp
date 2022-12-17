// Link: https://leetcode.com/problems/number-of-squareful-arrays/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int sum = A[i] + A[j];
                int root = (int)sqrt(sum);
                if (root * root == sum) {
                    graph[A[i]].insert(A[j]);
                    graph[A[j]].insert(A[i]);
                }
            }
        }
        unordered_map<int, int> counts;
        for (int a : A) {
            counts[a]++;
        }
        int res = 0;
        for (auto &p : graph) {
            int a = p.first;
            if (counts[a] > 0) {
                counts[a]--;
                res += dfs(graph, counts, a, n-1);
                counts[a]++;
            }
        }
        return res;
    }
    
    int dfs(unordered_map<int, unordered_set<int>> &graph, unordered_map<int, int> &counts, int a, int n) {
        if (n == 0) {
            return 1;
        }
        int res = 0;
        for (int b : graph[a]) {
            if (counts[b] > 0) {
                counts[b]--;
                res += dfs(graph, counts, b, n-1);
                counts[b]++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {1, 17, 8};
    cout << sol.numSquarefulPerms(A) << endl;
    return 0;
}
