// Link: https://leetcode.com/problems/smallest-good-base/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
    long long f(long long b, int n)
    {
        long long k = 1;
        for (int i = 1; i < n; ++i)
            k = k*b + 1;
        return k;
    }
    long long solve(long long k, int n)
    {
        long long bl = pow(k, 1./n), bh =  pow(k, 1./(n - 1) );
        if (n == 2) bh = k;
        while(bl <= bh)
        {
            long long mid = bl + (bh - bl) /2;
            long long t = f(mid, n);
            if (t > k)
                bh = mid - 1;
            else if (t < k)
                bl = mid + 1;
            else
                return mid;
        }
        return -1;
    }
public:
    string smallestGoodBase(string s) {
        long long k = stoll(s);
        for (int i = log2(k) + 1; i >= 3; --i )
        {
            long long b = solve(k, i);
            if (b != -1)
                return to_string(b);
        }
        return to_string(k - 1);
        
    }
};


int main() {
    string n = "13";
    Solution sol;
    cout << sol.smallestGoodBase(n) << endl;

    return 0;
}
