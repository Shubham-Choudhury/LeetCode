// Link: https://leetcode.com/problems/consecutive-numbers-sum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int k = 1; k * (k - 1) / 2 < N; ++k) {
            if ((N - k * (k - 1) / 2) % k == 0) {
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.consecutiveNumbersSum(5) << endl;
    cout << solution.consecutiveNumbersSum(9) << endl;
    cout << solution.consecutiveNumbersSum(15) << endl;
    return 0;
}