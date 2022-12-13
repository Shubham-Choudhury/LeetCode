// Link: https://leetcode.com/problems/find-the-closest-palindrome/

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        int len = n.size();
        vector<long> candidates;
        candidates.push_back((long)pow(10, len) + 1);
        candidates.push_back((long)pow(10, len - 1) - 1);
        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; i++)
        {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (len & 1), p.rend());
            candidates.push_back(stol(pp));
        }
        long num = stol(n), diff = LONG_MAX, res = 0;
        for (long c : candidates)
        {
            if (c == num)
                continue;
            if (abs(c - num) < diff || (abs(c - num) == diff && c < res))
            {
                diff = abs(c - num);
                res = c;
            }
        }
        return to_string(res);
    }
};

int main()
{
    Solution obj;
    string n;
    string res;

    n = "123";
    res = obj.nearestPalindromic(n);
    cout << res << endl;

    n = "1";
    res = obj.nearestPalindromic(n);
    cout << res << endl;

    n = "9";
    res = obj.nearestPalindromic(n);
    cout << res << endl;

    return 0;
}