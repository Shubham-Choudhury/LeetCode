// Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
   int findKthNumber(int n, int k)
    {
        int result = 1;
        for(--k; k > 0; )
        {            int count = 0;
            for (long long first = static_cast<long long>(result), last = first + 1;
                first <= n; 
                first *= 10, last *= 10) 
            {
                count += static_cast<int>((min(n + 1LL, last) - first)); 
            }
            
            if (k >= count)
            {   
                ++result;
                k -= count;
            }
            else
            {   
                result *= 10;
                --k;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    int n = 13;
    int k = 2;
    cout << s.findKthNumber(n, k) << endl;
    return 0;
}