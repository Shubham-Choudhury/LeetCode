// Link: https://leetcode.com/problems/letter-tile-possibilities/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        int n = tiles.size();
        vector<int> freq(26, 0);
        for (auto &x : tiles)
            freq[x - 'A']++;
        return dfs(freq);
    }

    int dfs(vector<int> &freq)
    {
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
                continue;
            res++;
            freq[i]--;
            res += dfs(freq);
            freq[i]++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string tiles = "AAB";
    cout << sol.numTilePossibilities(tiles) << endl;
    return 0;
}
