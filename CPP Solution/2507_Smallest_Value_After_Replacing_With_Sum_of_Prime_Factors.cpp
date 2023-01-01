// Link: https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
	int smallestValue(int n) {
		while (true) {
			int sm = 0; 
			for (int f = 2, nn = n; f <= nn; ++f) 
				for (; nn % f == 0; nn /= f, sm += f); 
			if (sm == n) break; 
			n = sm;
		}
		return n; 
	}
};

int main(){
    Solution s;
    int n = 10;
    cout << s.smallestValue(n) << endl;
    return 0;
}