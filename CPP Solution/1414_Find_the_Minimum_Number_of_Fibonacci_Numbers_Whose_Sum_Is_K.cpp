// Link: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int findMinFibonacciNumbers(int k)
    {
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        int i = 2;
        while (fib[i - 1] + fib[i - 2] <= k)
        {
            fib.push_back(fib[i - 1] + fib[i - 2]);
            i++;
        }
        int ans = 0;
        for (int i = fib.size() - 1; i >= 0; i--)
        {
            if (k >= fib[i])
            {
                k -= fib[i];
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int k = 19;
    int ans = sol.findMinFibonacciNumbers(k);
    cout << ans << endl;
    return 0;
}
