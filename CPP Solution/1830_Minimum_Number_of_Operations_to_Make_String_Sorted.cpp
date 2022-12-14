// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;
    long long modpow(long long b, long long p)
    {
        long long ans = 1;
        for (; p; p >>= 1)
        {
            if (p & 1)
                ans = ans * b % mod;
            b = b * b % mod;
        }
        return ans;
    }
    int makeStringSorted(string s)
    {
        long long ans = 0;
        map<int, long long> freq;
        for (char &c : s)
        {
            freq[c - 'a']++;
        }
        vector<long long> fact(s.size() + 1, 1ll);
        for (int i = 1; i <= s.size(); i++)
        {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        int l = s.size();
        for (char c : s)
        {
            l--;
            long long t = 0, rev = 1;
            for (int i = 0; i < 26; i++)
            {
                if (i < c - 'a')
                    t += freq[i];
                rev = (rev * fact[freq[i]]) % mod;
            }
            ans += (t * fact[l] % mod) * modpow(rev, mod - 2);
            ans %= mod;
            freq[c - 'a']--;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s;
    int ans;

    // Output: 5
    s = "cba";
    ans = sol.makeStringSorted(s);
    cout << ans << endl;

    // Output: 22
    s = "aabaa";
    ans = sol.makeStringSorted(s);
    cout << ans << endl;

    // Output: 5
    s = "cdbea";
    ans = sol.makeStringSorted(s);
    cout << ans << endl;

    // Output: 3
    s = "leetcodeleetcodeleetcode";
    ans = sol.makeStringSorted(s);
    cout << ans << endl;

    return 0;
}
