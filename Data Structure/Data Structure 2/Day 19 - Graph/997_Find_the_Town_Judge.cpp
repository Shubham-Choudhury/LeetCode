// Link: https://leetcode.com/problems/find-the-town-judge/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N + 1, 0);
        vector<int> out(N + 1, 0);
        for (auto t : trust) {
            out[t[0]]++;
            in[t[1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (in[i] == N - 1 && out[i] == 0)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    cout << s.findJudge(3, trust);
    return 0;
}