// Link: https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];
        int c = 0;
        for (int i = 2; i < n; i++) {
            c = cost[i] + min(a, b);
            a = b;
            b = c;
        }
        return min(a, b);
    }
};

int main() {
    Solution s;
    vector<int> cost = {10, 15, 20};
    cout << s.minCostClimbingStairs(cost) << endl;
    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s.minCostClimbingStairs(cost) << endl;
}