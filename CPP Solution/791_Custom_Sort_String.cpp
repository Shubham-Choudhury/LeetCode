// Link: https://leetcode.com/problems/custom-sort-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string str)
    {
        vector<int> count(26);
        for (auto c : str)
            ++count[c - 'a'];
        string result;
        for (auto c : order)
        {
            result += string(count[c - 'a'], c);
            count[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (count[i])
                result += string(count[i], i + 'a');
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string order, str, result;

    // Output: "cbad"
    order = "cba";
    str = "abcd";
    result = sol.customSortString(order, str);
    cout << result << endl;

    // Output: "cbad"
    order = "cba";
    str = "abcd";
    result = sol.customSortString(order, str);
    cout << result << endl;

    return 0;
}