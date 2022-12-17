// Link: https://leetcode.com/problems/remove-duplicate-letters/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int cnt[26] = {0};
        bool visited[26] = {false};
        for (char c : s)
        {
            cnt[c - 'a']++;
        }
        string result = "0";
        for (char c : s)
        {
            cnt[c - 'a']--;
            if (visited[c - 'a'])
            {
                continue;
            }
            while (c < result.back() && cnt[result.back() - 'a'] > 0)
            {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result += c;
            visited[c - 'a'] = true;
        }
        return result.substr(1);
    }
};

int main()
{
    Solution solution;
    string s = "bcabc";
    cout << solution.removeDuplicateLetters(s) << endl;
    return 0;
}
