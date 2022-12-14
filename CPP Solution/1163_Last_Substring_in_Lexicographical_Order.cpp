// Link: https://leetcode.com/problems/last-substring-in-lexicographical-order/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string lastSubstring(string s)
    {
        int n = s.length();
        int max_ind = n - 1;
        int i = n - 2;
        while (i >= 0)
        {
            if (s[i] > s[max_ind])
                max_ind = i;
            else if (s[i] == s[max_ind])
            {
                int j = 1;
                while ((max_ind + j) < n && s[i + j] == s[max_ind + j] && (i + j) != max_ind)
                    j++;

                if (s[i + j] >= s[max_ind + j] || (max_ind + j) >= n)
                    max_ind = i;
            }
            i--;
        }
        return s.substr(max_ind);
    }
};

int main()
{
    Solution s;
    string s1 = "abab";
    cout << s.lastSubstring(s1) << endl;
    return 0;
}
