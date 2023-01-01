// Link: https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
private:
    int gcd(int a, int b)
    {
        if (!b)
            return a;
        return gcd(b, a % b);
    }
    int lcm(ll a, ll b)
    {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uc1, int uc2)
    {
        int l = 1, r = INT_MAX, LCM = lcm(divisor1, divisor2);
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int a = mid / divisor1, b = mid / divisor2;
            if (uc1 <= mid - a && uc2 <= mid - b && uc1 + uc2 <= (mid - (mid / LCM)))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    Solution s;
    int divisor1 = 2, divisor2 = 3, uniqueCnt1 = 3, uniqueCnt2 = 5;
    cout << s.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2) << endl;
    return 0;
}