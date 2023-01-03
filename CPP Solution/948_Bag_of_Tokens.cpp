// Link: https://leetcode.com/problems/bag-of-tokens/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int P)
    {
        sort(tokens.begin(), tokens.end());
        int ans = 0, points = 0, i = 0, j = tokens.size() - 1;
        while (i <= j)
        {
            if (P >= tokens[i])
            {
                P -= tokens[i++];
                ans = max(ans, ++points);
            }
            else if (points > 0)
            {
                P += tokens[j--];
                points--;
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> tokens = {100};
    int P = 50;
    cout << sol.bagOfTokensScore(tokens, P) << endl;
    return 0;
}
