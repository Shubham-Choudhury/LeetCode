// Link: https://leetcode.com/problems/k-inverse-pairs-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int kInversePairs(int n, int k) {
	if(n == 1) return k == 0;
	if(k == 0) return 1;
	if(n == 2) return k == 1;
    
	unsigned int mod = 1000000007;
	vector<unsigned int> a (k+1, 0); 
	vector<unsigned int> b (k+1, 0);
    
	a[0] = a[1] = 1;
    
	for(int num = 3; num <= n; num++, swap(a, b)){
		b[0] = 1;
		int j = 1, i = 0;
		for(;j < num && j <= k ; j++,i++)
			b[j] = (a[j] + b[i]) % mod ;
      
		int w = 0;
		for(; j <= k && b[i];j++, i++)
			b[j] = (a[j] + b[i] + mod - a[w++]) % mod ;
	}
    
	return a[k];
	}
};

int main()
{
    Solution obj;
    int n, k, res;

    n = 3, k = 0;
    res = obj.kInversePairs(n, k);
    cout << res << endl;

    n = 3, k = 1;
    res = obj.kInversePairs(n, k);
    cout << res << endl;

    return 0;
}