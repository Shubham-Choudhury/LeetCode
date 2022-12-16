// Link: https://leetcode.com/problems/count-primes/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res++;
                for (int j = 2; i * j < n; j++) {
                    isPrime[i * j] = false;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.countPrimes(10) << endl;
    cout << a.countPrimes(0) << endl;
    cout << a.countPrimes(1) << endl;
    return 0;
}
