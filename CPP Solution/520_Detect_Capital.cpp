// Link: https://leetcode.com/problems/detect-capital/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        if (n == 1)
            return true;
        if (isupper(word[0]))
        {
            if (isupper(word[1]))
            {
                for (int i = 2; i < n; i++)
                    if (islower(word[i]))
                        return false;
            }
            else
            {
                for (int i = 2; i < n; i++)
                    if (isupper(word[i]))
                        return false;
            }
        }
        else
        {
            for (int i = 1; i < n; i++)
                if (isupper(word[i]))
                    return false;
        }
        return true;
    }
};

int main()
{
    Solution S;
    string word = "USA";
    cout << S.detectCapitalUse(word) << endl;
    return 0;
}
