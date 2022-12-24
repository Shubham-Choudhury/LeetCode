// Link: https://leetcode.com/problems/rabbits-in-forest/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int y: answers) {
            count[y]++;
        }
        int ans = 0;
        for (auto p: count) {
            int x = p.first, y = p.second;
            ans += (x + y) / (x + 1) * (x + 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> answers;
    int ans;

    // Output: 5
    answers = {1, 1, 2};
    ans = sol.numRabbits(answers);
    cout << ans << endl;

    // Output: 11
    answers = {10, 10, 10};
    ans = sol.numRabbits(answers);
    cout << ans << endl;

    // Output: 0
    answers = {};
    ans = sol.numRabbits(answers);
    cout << ans << endl;

    return 0;
}
