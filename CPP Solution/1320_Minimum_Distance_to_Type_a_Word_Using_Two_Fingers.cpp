// Link: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
        int minimumDistance(string word) {
        vector<int> dp(26);
        int res = 0, save = 0, n = word.size();
        for (int i = 0; i < n - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a)
                dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c));
            save = max(save, dp[b]);
            res += d(b, c);
        }
        return res - save;
    }

    int d(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};

int main() {
    Solution sol;
    string word;
    
    word = "CAKE";
    cout << sol.minimumDistance(word) << endl;
    
    word = "HAPPY";
    cout << sol.minimumDistance(word) << endl;
    
    word = "NEW";
    cout << sol.minimumDistance(word) << endl;
    
    word = "YEAR";
    cout << sol.minimumDistance(word) << endl;
    
    return 0;
}
