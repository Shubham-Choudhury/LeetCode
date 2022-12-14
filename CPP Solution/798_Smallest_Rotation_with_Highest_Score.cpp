// Link: https://leetcode.com/problems/smallest-rotation-with-highest-score/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int bestRotation(vector<int>& A) {
        const int N = A.size();
        
        vector<int> tmp(N+1, 0); 
        
        for (int i(0); i < N; ++i) {
            if (A[i] <= i) {
                
                tmp[0] += 1;
                tmp[i-A[i]+1] -= 1;
                tmp[i+1] += 1;
                tmp[N] -= 1;
            }
            else {
                
                tmp[i+1] += 1;
                tmp[N-A[i]+i+1] -= 1;
            }
        }
        
        int maxc = INT_MIN;
        int maxK = -1;
        int cur = 0;
        for (int i(0); i < N; ++i) {
            cur += tmp[i];
            if (cur > maxc) {
                maxc = cur;
                maxK = i;
            }
        }
        return maxK;
    }
};

int main()
{
    vector<int> A = {2, 3, 1, 4, 0};
    Solution obj;
    cout << obj.bestRotation(A) << endl;
    return 0;
}
