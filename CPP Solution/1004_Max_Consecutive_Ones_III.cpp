// Link: https://leetcode.com/problems/max-consecutive-ones-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int ans = 0;
        int left = 0;
        int right = 0;
        int count = 0;
        while (right < A.size())
        {
            if (A[right] == 0)
                count++;
            while (count > K)
            {
                if (A[left] == 0)
                    count--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> A = {1,1,1,0,0,0,1,1,1,1,0};
    int K = 2;
    cout << sol.longestOnes(A, K) << endl;
    return 0;
}