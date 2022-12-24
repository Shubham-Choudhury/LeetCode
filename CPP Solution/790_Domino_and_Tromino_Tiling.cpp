// Link: https://leetcode.com/problems/domino-and-tromino-tiling/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        int numTilings(int n) {
      if (n == 1) return 1;
      
      // initial values
      long a, a_pre1 = 1, a_pre2 = 1; // 2xn solution
      long b, b_pre1 = 1, b_pre2 = 0; // 2xn+1 solution
      const long mod = 1000000007;      
      
      while (--n >= 1) // iterate n-1 times
      { 
        a = (a_pre1 + a_pre2 + 2*b_pre2)%mod;
        b = (a_pre1 + b_pre1)%mod;
        
        // update a and b
        a_pre2 = a_pre1;
        a_pre1 = a;
        
        b_pre2 = b_pre1;
        b_pre1 = b;
      }
      return a;
    }
}; 

int main() {
    Solution sol;
    cout << sol.numTilings(3) << endl;
    cout << sol.numTilings(4) << endl;
    return 0;
}