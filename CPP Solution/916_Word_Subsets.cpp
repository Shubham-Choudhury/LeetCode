// Link: https://leetcode.com/problems/word-subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        vector<string> ans;
        vector<int> Bmax(26, 0);

        for (auto word : B)
        {
            vector<int> Bfreq(26, 0);
            for (auto ch : word)
                Bfreq[ch - 'a']++;

            for (int i = 0; i < 26; i++)
                Bmax[i] = max(Bmax[i], Bfreq[i]);
        }

        for (auto word : A)
        {
            vector<int> Afreq(26, 0);
            for (auto ch : word)
                Afreq[ch - 'a']++;

            bool flag = true;
            for (int i = 0; i < 26; i++)
                if (Afreq[i] < Bmax[i])
                {
                    flag = false;
                    break;
                }

            if (flag)
                ans.push_back(word);
        }

        return ans;
    }
};

int main()
{
    Solution S;
    vector<string> A = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> B = {"e", "o"};
    vector<string> ans = S.wordSubsets(A, B);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
