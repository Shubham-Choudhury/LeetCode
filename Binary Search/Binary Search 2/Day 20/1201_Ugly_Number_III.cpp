// Link: https://leetcode.com/problems/ugly-number-iii/?envType=study-plan&id=binary-search-ii

#include <iostream>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);
        long long left = 1;
        long long right = 2 * (long long)1e9;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count = mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
            if (count < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    
    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }
};

int main() {
    Solution s;
    cout << s.nthUglyNumber(3, 2, 3, 5);
    return 0;
}