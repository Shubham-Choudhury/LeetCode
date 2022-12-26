// Link: https://leetcode.com/problems/rotated-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rotatedDigits(int N)
    {
        int res = 0;
        for (int i = 1; i <= N; ++i)
        {
            int n = i;
            bool valid = false;
            while (n)
            {
                int d = n % 10;
                if (d == 3 || d == 4 || d == 7)
                {
                    valid = false;
                    break;
                }
                if (d == 2 || d == 5 || d == 6 || d == 9)
                    valid = true;
                n /= 10;
            }
            if (valid)
                ++res;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int N, result;

    // Output: 4
    N = 10;
    result = sol.rotatedDigits(N);
    cout << result << endl;

    // Output: 247
    N = 857;
    result = sol.rotatedDigits(N);
    cout << result << endl;

    return 0;
}