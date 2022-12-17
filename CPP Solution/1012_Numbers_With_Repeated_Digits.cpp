// Link: https://leetcode.com/problems/numbers-with-repeated-digits/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numDupDigitsAtMostN(int N)
    {
        vector<int> digits;
        for (int n = N + 1; n > 0; n /= 10)
        {
            digits.push_back(n % 10);
        }
        reverse(digits.begin(), digits.end());
        int n = digits.size();
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            res += 9 * A(9, i - 1);
        }
        unordered_set<int> seen;
        for (int i = 0; i < n; i++)
        {
            for (int j = (i == 0 ? 1 : 0); j < digits[i]; j++)
            {
                if (seen.count(j) == 0)
                {
                    res += A(9 - i, n - i - 1);
                }
            }
            if (seen.count(digits[i]) > 0)
            {
                break;
            }
            seen.insert(digits[i]);
        }
        return N - res;
    }

    int A(int m, int n)
    {
        int res = 1;
        for (int i = 0; i < n; i++)
        {
            res *= m - i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int N = 20;
    cout << sol.numDupDigitsAtMostN(N) << endl;
    return 0;
}
