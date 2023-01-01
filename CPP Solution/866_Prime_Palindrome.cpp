// Link: https://leetcode.com/problems/prime-palindrome/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n < 2)
        {
            return false;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int primePalindrome(int n)
    {
        while (true)
        {
            if (n == reverse(n) && isPrime(n))
            {
                return n;
            }
            n++;
            if (n > 10000000 && n < 100000000)
            {
                n = 100000000;
            }
        }
        return -1;
    }

    int reverse(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.primePalindrome(6) << endl;
    cout << s.primePalindrome(8) << endl;
    cout << s.primePalindrome(13) << endl;
    cout << s.primePalindrome(100) << endl;
    cout << s.primePalindrome(1000) << endl;
    cout << s.primePalindrome(100000000) << endl;
    return 0;
}
