// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || st.top().first != s[i])
                st.push({s[i], 1});
            else
            {
                st.top().second++;
                if (st.top().second == k)
                    st.pop();
            }
        }
        string res = "";
        while (!st.empty())
        {
            res = string(st.top().second, st.top().first) + res;
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    string s1 = "abcd";
    int k1 = 2;
    cout << s.removeDuplicates(s1, k1);
    return 0;
}
