// Link: https://leetcode.com/problems/reordered-power-of-2/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool reorderedPowerOf2(int N)
    {
        string s = to_string(N);
        sort(s.begin(), s.end());
        do
        {
            if (s[0] != '0' && isPowerOfTwo(stoi(s)))
            {
                return true;
            }
        } while (next_permutation(s.begin(), s.end()));
        return false;
    }

    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main()
{
    Solution s;
    cout << s.reorderedPowerOf2(1) << endl;
    cout << s.reorderedPowerOf2(10) << endl;
    cout << s.reorderedPowerOf2(16) << endl;
    cout << s.reorderedPowerOf2(24) << endl;
    cout << s.reorderedPowerOf2(46) << endl;
    return 0;
}
