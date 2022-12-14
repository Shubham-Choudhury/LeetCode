// Link: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    int mod = pow(10, 9) + 7;

public:
    int uniqueLetterString(string s)
    {
        vector<vector<int>> index(26, vector<int>(2, -1));
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'A';
            ans = (ans + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int c = 0; c < 26; ++c)
            ans = (ans + (n - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.uniqueLetterString("ABC") << endl;
    cout << solution.uniqueLetterString("ABA") << endl;
    cout << solution.uniqueLetterString("LEETCODE") << endl;
    return 0;
}
