// Link: https://leetcode.com/problems/similar-string-groups/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(A[i], A[j])) {
                    unionSet(parent, i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                ++ans;
            }
        }
        return ans;
    }
    
    bool isSimilar(string &a, string &b) {
        int n = a.length();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ++count;
            }
        }
        return count == 2 || count == 0;
    }
    
    int findSet(vector<int> &parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findSet(parent, parent[x]);
    }
    
    void unionSet(vector<int> &parent, int x, int y) {
        int px = findSet(parent, x);
        int py = findSet(parent, y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

int main()
{
    Solution solution;
    vector<string> A = {"tars","rats","arts","star"};
    cout << solution.numSimilarGroups(A) << endl;
    return 0;
}
