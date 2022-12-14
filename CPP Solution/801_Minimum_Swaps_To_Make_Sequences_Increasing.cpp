// Link: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        
        vector<int> swap(N, INT_MAX);
        vector<int> noswap(N, INT_MAX);
        
        swap[0] = 1;
        noswap[0] = 0;
        
        for (int i(1); i < N; ++i) {
            if (A[i] > A[i-1] && B[i] > B[i-1]) {
                swap[i] = swap[i-1] + 1;
                noswap[i] = noswap[i-1];
            }
            if (A[i] > B[i-1] && B[i] > A[i-1]) {
                swap[i] = min(swap[i], noswap[i-1] + 1);
                noswap[i] = min(noswap[i], swap[i-1]);
            }
        }
        
        return min(swap[N-1], noswap[N-1]);
    }
};

int main()
{
    vector<int> A = {1, 3, 5, 4};
    vector<int> B = {1, 2, 3, 7};
    Solution obj;
    cout << obj.minSwap(A, B) << endl;
    return 0;
}
