// Link: https://leetcode.com/problems/maximum-sum-circular-subarray/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int maxSum = A[0];
        int sum = 0;
        for (int num : A) {
            if (sum > 0) {
                sum += num;
            } else {
                sum = num;
            }
            maxSum = max(maxSum, sum);
        }
        int minSum = A[0];
        sum = 0;
        for (int num : A) {
            if (sum < 0) {
                sum += num;
            } else {
                sum = num;
            }
            minSum = min(minSum, sum);
        }
        int totalSum = 0;
        for (int num : A) {
            totalSum += num;
        }
        return totalSum == minSum ? maxSum : max(maxSum, totalSum - minSum);
    }
};

int main(){
    Solution s;
    vector<int> A = {1, -2, 3, -2};
    cout << s.maxSubarraySumCircular(A) << endl;
    return 0;
}